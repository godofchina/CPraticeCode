#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define	TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int ElemType;

//data struct
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *Llist;

int InitList(Llist *L)
{
	//apply memory for list
	*L = (Llist) malloc(sizeof(LNode));
	if (!L)
	{
		return ERROR;
	}

	//turn the poniter to NULL
	(*L)->next = NULL;
	return OK;
}

//there is a problem haven't understood (how to understand arg L?)
int InsertNode(Llist L, int i, ElemType e)
{
	//figure out the position of the Element
	int j = 0;
	Llist p=L;
	while ( p && j < i-1 )
	{
		j++;
		p = p->next;
	}

	//judge the boundary
	if ( !p || j > i-1 )
	{
		return ERROR;
	}

	//insert a node to the list
	//forget to apply memory for new node
	Llist a;
	a = (Llist) malloc(sizeof(LNode));
	a->data = e;
	a->next = p->next;
	p->next = a;
	return OK;
}

int GetElem(Llist L, int i, ElemType *e)
{
	//first step is the same as insertnode
	int j = 0;
	Llist p=L->next;
	while ( p && j < i-1 )
	{
		j++;
		p = p->next;
	}

	//second step is also same as insertnode
	if ( !p || j > i-1 )
	{
		return ERROR;
	}

	*e = p->data;
	return OK;
}

int main()
{
	Llist L;
	if ( InitList(&L) )
	{
		printf("InitList successful\n");

		ElemType e;

		if ( InsertNode(L, 1, 12) )
		{
			printf("InsertNode successful\n");
		}

		if ( GetElem(L, 1, &e) ) 
		{
			printf("Element:%d\n", e);
		}
	}

	return 0;
}