#include <stdio.h>
#include <stdlib.h>

struct binode
{
    int value;
    struct btnode *l;
    struct btnode *r;
};

struct binode *root;
struct binode *temp;

typedef struct btnode N;

void insert();
N* bt(int arr[], int, int);
N* new(int);
void inorder(N *t);
void create();
void search(N *t);
void preorder(N *t);
void postorder(N *t);

void main()
{
    
}
