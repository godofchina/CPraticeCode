#include <stdio.h>

//void swap(int * point_1, int * point_2);

int main()
{
    int *p1, *p2, *p, a, b;
    void swap(int x, int y);
    printf("please enter two integer number:");
    scanf("%d, %d", &a, &b);

    p1=&a;
    p2=&b;

    if (a<b)
        swap(a, b);

    printf("max=%d, min=%d\n", a, b);

    return 0;
}

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

/*void swap(int * point_1, int * point_2)
{
    int temp;

    temp = * point_1;
    *point_1 = *point_2;
    *point_2 = temp;
}*/
