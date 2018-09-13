#include <stdio.h>

int main()
{
    int i, *p, a[10];
    p = a;
    /*
    for (i=0;i<10;i++) {
        scanf("%d", a+i);
    }

    for (i=0;i<10;i++) {
        printf("i=%d\n", i);
        printf("%d\n", *p++);
    }
    */
    int b=1;
    printf("b++=%d", b++);
    printf("b=%d", b);
    return 0;
}
