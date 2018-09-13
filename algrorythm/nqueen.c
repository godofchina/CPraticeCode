/**
* n皇后问题
* date       : 2010-3-12
* author     : lee
* change     ：LinE
* change date：2014-8-4
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define QUEEN 9    // the number of the queen
#define INITIAL -10000  //defines the initial value of  the board
 
//container
int a[QUEEN];
 
//check if the queen can be placed on the position
int valid(int row, int col);
//initialize the board
void clear();
//print the result
void print();
//run the n-queen program
void queen();
 
int main(void)
{
    clear();
    queen();
    return 0;
}
 
void clear()
{
    int *p;
    for (p = a; p < a + QUEEN; ++p) {
        *p = INITIAL;
    }
}
 
void print()
{
    int i,j,l;
    for (i = 0; i < QUEEN; ++i) {
        for (j = 0; j < QUEEN; ++j) {
            if (a[i] != j) {
               //printf("%c ", &#039;.&#039;);
             }
            else
            {
                 l=j+1;
                printf("%d",l);
                //printf("%c ", &#039;#&#039;);
            }
        }
    }
    printf("\n");
    //printf("--------------------------------------------\n");
}
 
int valid(int row, int col)
{
    int i;
    for (i = 0; i < QUEEN; ++i) {
        if (a[i] == col || abs(i - row) == abs(a[i] - col))
            return 0;
    }
 
    return 1;
}
 
void queen()
{
    int n = 0;
    int i = 0, j = 0;
    while (i < QUEEN) {
 
        while (j < QUEEN) {
            if (valid(i, j)) { //test if the queen can be placed on the position
                a[i] = j;     //place the queen on the next line
                j = 0;
                break;
            } else {         // if not, check the next position
                ++j;
            }
        }
 
        if (a[i] == INITIAL) {   //if the current queen can&#039;t find its place
            if (i == 0)        // and this is the first line ,then program end
                break;
            else  {           //else   backtrack
                --i;
                j = a[i] + 1;
                a[i] = INITIAL;
                continue;
            }
        }
 
        if (i == QUEEN - 1) {  //already got a solution, print the result
            //printf("answer %d : \n", ++n);
            print();
        //  _sleep(600);
            j = a[i] + 1;
            a[i] = INITIAL;
            continue;
 
        }
 
        ++i;      // go on to place the queen on the next line if has any more
    }
}
