#include <stdio.h>
#include <stdlib.h>

//data struct 
typedef struct
{
	char* name;		//key
	char* value;	//value
	struct node *next; 
}node;