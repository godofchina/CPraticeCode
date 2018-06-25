#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void pr_exit(int status);

int main(void)
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(-1);
    } else if (pid == 0) {
        sleep(1);
        printf("in child\n");
        exit(101);
    }

    if (wait(&status) != pid) {
        perror("wait");
        exit(-2);
    }

    printf("in parent\n");
    pr_exit(status);
    
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(-1);
    } else if (pid == 0) {
        abort();
    }

    if (wait(&status) != pid) {
        perror("wait");
        exit(-2);
    }

    pr_exit(status);
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(-1);
    } else if (pid == 0)
        status /= 0;

    if (wait(&status) != pid) {
       perror("wait");
       exit(-1);
    }

    pr_exit(status);
    exit(0);
}

void pr_exit(int status) {
    if (WIFEXITED(status))
        printf("normallytermination, low-order 8 bit of exit status = %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("abnormallytermination, signal number = %d\n", WTERMSIG(status));
}
