#include <stdio.h>

int main()
{
    int a[10] = {0, 1, 2, 3, 4};
    int *pointer;
    pointer = a;
    printf("pointer = %d", pointer[2]);

    return 0;
}
