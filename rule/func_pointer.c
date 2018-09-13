#include <stdio.h>
#include <stdlib.h>

void (*funP)(int);
void (*funA)(int);
void myFun(int x);
int *myFunc(int x);

int main()
{
    myFun(122);
    myFunc(14500);
    /*
    funP = &myFun;
    (*funP)(1000);
    
    funA = myFun;
    (*funA)(400);
    
    (*myFun)(2000);
    */

    return 0;
}

int *myFunc(int x)
{
    int *p;
    return p;
}

void myFun(int x) 
{
    printf("myFun: %d\n", x);
}
