#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define INIT_SIZE 10
#define INCREMENT 5

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType *elem;		//存储空间基址
	int size;			//当前分配的表长
	int length;			//表长
}list;

//初始化
Status InitList(list *L)
{	
	//申请内存
	L->elem = (ElemType *) malloc( sizeof( INIT_SIZE * sizeof(ElemType) ) );
	if (!L->elem) 
	{
		return ERROR;
	}
	L->length = 0;			//当前表长
	L->size   = INIT_SIZE;	//分配的表长
	return OK;
}

//删除
Status Destory(list *L)
{	
	//释放内存
	free(L->elem);
	L->size   = 0;
	L->length = 0;
	return OK;
}

//清空
Status Clear(list *L)
{
	L->size = 0;
	return 0;
}

//insert specific element to specific position
Status Insert(list *L,int i, ElemType e)
{
	//为新申请的内存提前准备个容器
	ElemType *new;

	//边界检测
	if (i < 1 || i > L->length + 1)
	{
		return ERROR;
	}

	//是否需要申请内存
	if ( L->length >= L->size )
	{
		new = (ElemType*) realloc(L->elem, (L->size + INCREMENT) * sizeof(ElemType));
		if (!new)
		{
			return ERROR;
		}
		L->elem = new;
		L->size += INCREMENT;
	}

	//把插入位置以后的元素统一往后移动
	ElemType *current = &L->elem[i - 1];
	ElemType *second_last = &L->elem[L->length - 1];
	for (; second_last >= current; second_last--)
	{
		*(second_last+1) = *second_last;
	}

	*current = e;
	++L->length;
	return OK;
}

//compare two element
Status Compare(ElemType e1, ElemType e2)
{
	if (e1 == e2)
	{
		return 0;
	}
	else if (e1 > e2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

//calculate the current length of this lineartable
Status GetLength(const list L)
{
	return L.length;
}

//查找元素位置

//查找指定位置的元素
Status GetElemByIndex(const list L, int i, ElemType *e)
{
	if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.elem[i-1];
    return OK;
} 

Status Traverse(const list L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%d\n", L.elem[i]);
	}
	return OK;
}

//find the prev element

//find next element

//delete specific element

int main()
{
	list L;
	if ( InitList(&L) ) 
	{
		printf("init success\n");
		
		int i=1;

		for (i = 0; i < 10; i++)
		{
			if ( !Insert(&L, i+1, i) )
			{
				printf("%d insert failed\n",i);
			}
		}
		printf("length is:%d\n", GetLength(L));

		ElemType e;
		GetElemByIndex(L, 3, &e);
		//被自己蠢死了（这TM不是bug脑子抽了）
		printf("get element of specific index:%d\n", e);

		

		printf("Traverse:\n");
		Traverse(L);
		if ( Destory(&L) )
		{
			printf("destory success\n");
		}
	}
	// typedef 使用 赋值问题
}