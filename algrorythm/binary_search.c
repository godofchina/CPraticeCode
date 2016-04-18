#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR 0
#define OK 	  1

//no-recursion version
int binary_search(int *arr, int needle, int high, int low)
{
	int mid;

	while ( low <= high )
	{
		mid = (high+low) / 2; //(low+high)/2会有整数溢出的问题 ?整数溢出
		if ( needle == arr[mid] )
		{
			return arr[mid];
		}
		else if ( needle < arr[mid] )
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return ERROR;
}

//recursion version
int binary_search_recursion(int *arr, int needle, int high, int low)
{
	//边界检测
	if ( low > high ) 
	{
		return ERROR;
	}

	int mid;
	mid = (low+high)/2;
	if ( needle == arr[mid] )
	{
		return mid;
	}
	else if ( needle < arr[mid] )
	{
		binary_search_recursion(arr, needle, mid-1, low);
	}
	else
	{
		binary_search_recursion(arr, needle, high, mid+1);
	}
}

int main()
{
	int n;
	int needle;
	int *arr; //define a array prepare for the input

	//define array length
	printf("Please enter arr length:\n");
	scanf("%d",&n);

	//apply memory
	arr = (int*) malloc(sizeof(int) * n);

	printf("Please input %d intgers:\n", n);
	int i = 0;
	for (; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	printf("Please input needle:\n");
	scanf("%d", &needle);

	printf("search result is:%d\n", binary_search_recursion(arr, needle, n-1, 0));

	return 0;
}