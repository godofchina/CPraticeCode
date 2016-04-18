#include <stdio.h>

//函数的3种传参方式

//传递值
void swap1(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//传递指针
void swap2(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//引用传递(传言说C不支持引用传参 是真的 编译不通过) 
void swap3(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a=3,b=5;
	swap1(a,b);
	swap2(&a,&b);
	// swap3(a, b);

	printf("a:%d,b:%d\n", a, b);
	return 0;
}