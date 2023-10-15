#include "stdio.h"
#include "stdlib.h"
#include"string.h"
typedef struct 
{
    char *ch;
    int length;
} HeapString;

typedef enum {
    OVERFLOW,
    OK,
    ERROR,
    INVALID_STACK_NUM
} Status;
//串的连接操作
Status str_contract(HeapString*t,HeapString*s1,HeapString*s2)
{
    if(t->ch)
    {
        free(t->ch);
        t->ch=NULL;
    }
    t->length=s1->length+s2->length;
    if(t->ch=(char*)malloc(sizeof(char)*t->length)==NULL)
    return ERROR;
    for(int j=0;j<s1->length;j++)
    {
        t->ch[j]=s2->ch[j];
    }
    for(int i=s1->length,j=0;j<s2->length;i++,j++)
    {
        t->ch[i]=s2->ch[j];
    }
    return OK;
}