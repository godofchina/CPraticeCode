#include <stdio.h>
#define TEST(a, b)  a++;

int main()
{
    int a=1;
    int b=1;
    if (1)
        TEST(a, b)
    else
        printf("hello world");
}
