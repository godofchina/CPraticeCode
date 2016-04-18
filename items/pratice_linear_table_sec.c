#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define INIT_SIZE 10
#define INCERMENT 5

typedef int ElemType;
typedef int Status;

//data strcut
typedef struct
{
	ElemType *elem;		//address of the dataset
	int length;			
	int size;
}list;

Status InitList(list *L)
{
	L->elem = (ElemType *) malloc(INIT_SIZE * sizeof(ElemType));
	if ( !L->elem )
	{
		return ERROR;
	}
	L->length = 0;
	L->size   = INIT_SIZE;
	return OK;
}

Status InsertNode(list *L, int i, ElemType e)
{
	//judgement of boundary
	if ( i < 0 && i > L->length )
	{
		return ERROR;
	}

	//judgement of memory application
	if ( L->length > L->size )
	{
		//apply memory for new element
		L->elem = (ElemType *) malloc((L->length+INCERMENT) * sizeof(ElemType));
		if ( !L->elem )
		{
			return ERROR;
		}
		L->size += INCERMENT;
	}

	//high to low move
	int *low = &L->elem[i-1];
	int *high = &L->elem[L->length-1];
	while ( low < high && high-- )
	{
		*(high+1) = *high;
	}
	L->elem[i-1] = e;
	++L->length;
	return OK;
}

Status GetElem(list L, int i, ElemType *e)
{
	//judgement of boundary
	if ( i<0 || i>L.length )
	{
		return ERROR;
	}

	*e = L.elem[i-1];
	return OK;
}

int main()
{
	list L;
	if ( InitList(&L) )
	{
		printf("initlist successful\n");
		if ( InsertNode(&L, 1, 12) )
		{
			printf("insertnode successful\n");
			ElemType e;
			if ( GetElem(L, 1, &e) )
			{
				printf("1'th element:%d\n", e);
			}
		}
	}
	return 0;
}