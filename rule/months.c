#include <stdio.h>

int main()
{
     char *month[12] = {"January", "Fabuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

     int mon;

     printf("Please enter a number:\n");
     scanf("%d", &mon);
    
     if (mon <= 12 && mon > 0) 
     {
        printf("%s\n", *(month+mon-1));
     }
     else
        printf("error input\n");

     return 0;
}
