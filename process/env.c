#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char *envp[])
{
    char **ptr;
    //**ptr ptr 含义 此处存在疑问
    for (ptr = envp; *ptr != 0; ptr++)
        printf("%s\n", *ptr);
    
    printf("\n\n--------My environment variable-------\n\n");
    printf("USERNAME is %s\n", getenv("USERNAME"));
    
    putenv("USERNAME=ningjin");
    printf("USERNAME is %s\n", getenv("USERNAME"));

    setenv("USERNAME", "ningjin-1", 0);
    printf("USERNAME is %s\n", getenv("USERNAME"));

    setenv("USERNAME", "ningjin-1", 1);
    printf("USERNAME is %s\n", getenv("USERNAME"));
    return 0;
}
