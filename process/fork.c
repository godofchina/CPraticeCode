#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define err_sys(info) \
{\
    printf("%s\n", info);\
    exit(0);\
}\

int glob = 6;
char buf[] = "a write to stdout";

int main(void)
{
    int var;
    pid_t pid;
    var = 12;
    
    printf("sizeof(buf) is %ld\n", sizeof(buf));

    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1) {
        err_sys("write error");
    }

    printf("befork fork\n");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        glob++;
        var++;
    } else {
        sleep(20);
    }

    printf("pid = %d, ppid = %d, glob = %d, var = %d\n", getpid(), getppid(), glob, var);
    exit(0);
}
