#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

#define INIT_SIZE 5
#define INCERMENT 5

typedef int ElemType;

typedef struct
{
	ElemType *elem;
	int length;
	int size;
}List;

int InitList(List *L)
{
	//apply memory for list
	//integer poniert
	L->elem = (ElemType *) malloc(INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
	{
		return ERROR;
	}
	L->length = 0;
	L->size = INIT_SIZE;
	return OK; 
}

//插入元素需要做哪些操作(越界的那一次操作没有给元素附上值)
int InsertElem(List *L, int i, ElemType e)
{
	//边界判断
	if ( i<1 || i > L->length+1 )
	{
		return ERROR;
	}

	ElemType *new;
	//whether it needs to apply memory for new element
	if ( L->length > L->size )
	{
		new = (ElemType*) realloc(L->elem, (L->length + INCERMENT) * sizeof(ElemType));
		if ( !new )
		{
			return ERROR;
		}

		L->elem = new;
		L->length += INCERMENT;
	}

	//把i以后的元素向后移动 高位向低位移动
	ElemType *p = &L->elem[i - 1];			//第i个的位置
    ElemType *q = &L->elem[L->length - 1];	//最后一个元素的位置

    //逐个往后退一
    for (; q >= p; q--)
    {
        *(q + 1) = *q;
    }
    *p = e;

	++L->length;
	return OK;
}

int findElemByIndex(List L, int i, ElemType *e)
{
	if ( i<0 || i>L.length )
	{
		return ERROR;
	}
	*e = L.elem[i-1];
	return OK;
}


int main()
{
	//initilize a linear_table
	List L;
	if ( InitList(&L) )
	{
		printf("InitList successful\n");
		ElemType e;
		//tips
		printf("Please enter the length of arr\n");
		int num;
		scanf("%d",&num);

		//计算一元多项式的和 
		//思路 把每一项的值存入一个节点 遍历节点相加 求和

		int arr[num],i=0;
		printf("Please input each element:\n");
		for (;i < num; i++)
		{
			scanf("%d", &arr[i]);
			InsertElem(&L, i+1, arr[i]);
		}

		int sum = 0;
		i = 0;
		for (;i < num; i++)
		{
			printf("i:%d\n", i);
			printf("e:%d\n", L.elem[i]);
			sum += L.elem[i];
		}
		printf("\nsum:%d\n", sum);
	}


}