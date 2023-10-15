#include "stdlib.h"
#include "stdio.h"
#define MAXSIZE 10
typedef int QElemType;
typedef struct
{
    QElemType *base;
    int front;
    int rear;
}SqQueue;
typedef enum {
    OVERFLOW,
    OK,
    ERROR,
    INVALID_STACK_NUM
} Status;
Status init_queue(SqQueue*Q)
{
    Q->base=(QElemType*)malloc(MAXSIZE*sizeof(QElemType));
    Q->front=Q->rear=0;
    return OK;
}
int Queue_length(SqQueue*Q)
{
    return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}
Status enter_queue(SqQueue*Q,QElemType e)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
    return ERROR;
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}
Status de_queue(SqQueue*Q,QElemType*e)
{
    if(Q->front==Q->rear)
    {
        return ERROR;
    }
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return OK;
}
