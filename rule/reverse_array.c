#include <stdio.h>
#define NELEMS(x) (sizeof(x)/sizeof(x[0]))
int main()
{
    void reverse_array(int arr[], size_t n);
    void reverse_array_v2(int *arr, size_t n);
    void print_array(int arr[], size_t n);
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    size_t n = NELEMS(a); 
    print_array(a, n);
    //reverse_array(a, n);
    reverse_array_v2(a, n);
    print_array(a, n);
}

void reverse_array_v2(int *arr, size_t n)
{
    int *p, temp, *i,*j,m=(n-1)/2;

    i=arr;j=arr+n-1;p=arr+m;
    for (;i<p;i++,j--)
    {
        temp = *i;
        *i = *j;
        *j = temp;
    }
}

void reverse_array(int arr[], size_t n)
{
   int i, j, m, temp;
   m = (n-1) / 2;
   j = n-1;

   for (i=0; i<m; i++) 
   {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
   }
}

void print_array(int arr[], size_t n)
{
    int i;
    for (i=0; i<n; i++) 
    {
        printf("%d of arr is %d\n", i, *arr++);
    }
}
