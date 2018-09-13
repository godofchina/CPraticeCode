#include <stdio.h>

int main()
{
    void swap_value(int *pointer1, int *pointer2, int *pointer3);
    int a, b, c, *pointer1, *pointer2, *pointer3;
    a = 1;
    b = 2;
    c = 3;
    pointer1 = &a;
    pointer2 = &b;
    pointer3 = &c;
    printf("a = %d, b = %d, c = %d", a, b, c);
    swap_value(pointer1, pointer2, pointer3);
    printf("a = %d, b = %d, c = %d", a, b, c);
    
    return 0;
}

void swap_value(int *pointer1, int *pointer2, int *pointer3)
{
    int temp1, temp2, temp3;
    printf("pointer1 = %d", *pointer1);
    temp1 = *pointer1;
    temp2 = *pointer2;
    temp3 = *pointer3;
    *pointer2 = temp1;
    *pointer3 = temp2;
    *pointer1 = temp3;
}
