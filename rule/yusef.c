#include <stdio.h>
#include <string.h>

int main()
{
    void yusef(int n, int m);
    int n,m,x;
    scanf("%d,%d", &n, &m);
    /*
    int arr[10];
    memset(arr, 1, sizeof(arr));
    for (int i=0;i<10;i++) {
       printf("%d\t", arr[i]);
    }
    */
    yusef(n, m);

    return 0;
}

void yusef(int n, int m)
{
    int arr[n];
    for(int i=0;i<n;i++){arr[i] = 1;}
    int leftCount = n;
    int index=0,counter=0;
    
    while(leftCount>1) {
        if(arr[index] == 1){
            counter++;
            if(m == counter) {
                arr[index] = 0;
                counter = 0;
                leftCount--;
            }
        }
        index++;

        if(index == n){index=0;}
    }

    for(int j=0;j<n;j++){             // 输出结果
        if(1 == arr[j])
        { 
            printf("剩下一个人为第%d个\n",j+1); 
        }
    }    
}
