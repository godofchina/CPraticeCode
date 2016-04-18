//#include "stdafx.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

//哈希表的链地址法实现(将冲突的都放在一个表里)
//data struct
typedef struct _node
{
    char *name;         //key
    char *desc;         //value
    struct _node *next; //next node address
} node;

#define HASHSIZE 101   //define hashzize
static node* hashtab[HASHSIZE];

//挖好足够的坑 备用
void inithashtab()
{
    int i;
    for(i=0; i < HASHSIZE; i++)
        hashtab[i]=NULL;
}

//这就是所谓的hash算法（比较简单的一种）
unsigned int hash(char *s)
{
    unsigned int h=0;

    //将每个字符串的地址都加入生成hash键的过程(还是TMD看懂了)
    for(; *s; s++) {
        h=*s+h*31;
    }
    return h%HASHSIZE;
}

//look for the specific value
node* lookup(char *n)
{
    unsigned int hi=hash(n);

    //找到对应地址的链表
    node* np=hashtab[hi];

    //遍历对比在这个链表里是否有要找的值 找到就返回
    for(; np!=NULL; np=np->next)
    {
        if(!strcmp(np->name,n))
            return np;
    }

    return NULL;
}

//复制字符串 自己封装的一个类似 strdup 的方法 fuck
char* m_strdup(char *o)
{
    int l=strlen(o)+1;
    char *ns=(char*)malloc(l*sizeof(char));
    strcpy(ns,o);
    if(ns==NULL)
        return NULL;
    else
        return ns;
}

//find value by name
char* get(char* name)
{
    node* n=lookup(name);
    if(n==NULL)
        return NULL;
    else
        return n->desc;
}

//散列化 字符串键 为对应的 整型数字 把萝卜放到对应的坑里面
int install(char* name,char* desc)
{
    unsigned int hi;
    node* np;
    //先看坑里面有没有一坨
    //没有就放进去
    if((np=lookup(name))==NULL)
    {
        hi=hash(name);
        np=(node*)malloc(sizeof(node));
        if(np==NULL)
            return 0;
        // np->name=m_strdup(name); //这一步到底是干嘛的 去掉也不影响 这TMD的是作者自己封装的strdup函数(为什么要这样封装)
        np->name = name;
        if(np->name==NULL) return 0;
        np->next=hashtab[hi];
        hashtab[hi]=np;
    }//有就踢掉他 再放进去新的
    else
        free(np->desc);
    np->desc=m_strdup(desc);
    if(np->desc==NULL) return 0;

    return 1;
}

/* A pretty useless but good debugging function,
which simply displays the hashtable in (key.value) pairs
*/
void displaytable()
{
    int i;
    node *t;
    for(i=0; i < HASHSIZE; i++)
    {
        if(hashtab[i]==NULL)
            printf("()");
        else
        {
            t=hashtab[i];
            printf("(");
            for(; t!=NULL; t=t->next)
                printf("(%s.%s) ",t->name,t->desc);
            printf(".)");
        }
    }
}

void cleanup()
{
    int i;
    node *np,*t;
    for(i=0; i < HASHSIZE; i++)
    {
        if(hashtab[i]!=NULL)
        {
            np=hashtab[i];
            while(np!=NULL)
            {
                t=np->next;
                free(np->name);
                free(np->desc);
                free(np);
                np=t;
            }
        }
    }
}

main()
{
    int i;
    char* names[]= {"name","address","phone","k101","k110","nickname"};
    char* descs[]= {"Sourav","Sinagor","26300788","Value1","Value2","ningjin"};

    inithashtab();
    for(i=0; i < 6; i++)
        install(names[i],descs[i]);

    // get("k110");
    printf("Done");
    printf("If we didnt do anything wrong..""we should see %s\n",get("k110"));

    install("phone","9433120451");

    printf("Again if we go right, we have %s and %s",get("k101"),get("phone"));

    // printf("\nnickname:%s\n", get("nickname"));
    displaytable();
    cleanup();
    return 0;
}
