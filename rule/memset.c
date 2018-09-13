#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    
    char *example="This is string.h library function";
    strcpy(str, example);
    puts(str);
   
    memset(str, '$', 7);
    puts(str);
    
    int status[1000];
    memset(status, 0, sizeof(status));
    size_t n=sizeof(status)/sizeof(status[0]);
    printf("%ld\n", n);
    int *j, *p;
    j = status;
    p = status+n-1;
    for (;j<=p;j++)
    {
        printf("%d\t", *j);
    }

    return 0;

}
