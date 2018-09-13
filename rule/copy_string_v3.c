#include <stdio.h>

int main()
{
    void copy_string(char *from, char *to);

    char *a="I love programming";
    char b[]="I can improve my mathematics";
    char *to=b;

    printf("a=%s,b=%s\n", a, b);

    copy_string(a, to);
    printf("a=%s,b=%s\n", a, b);

    return 0;
}

void copy_string(char from[], char to[])
{
    for(;*from!='\0';from++,to++)
    {
        *to=*from;
    }

    *to='\0';
}
