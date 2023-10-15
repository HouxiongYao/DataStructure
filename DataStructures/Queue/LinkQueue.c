# include"stdlib.h"
# include"stdio.h"
typedef int QElemType; 
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct LinkQueue
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

typedef enum {
    OVERFLOW,
    OK,
    ERROR,
    INVALID_STACK_NUM
} Status;
Status init_queue(LinkQueue*Q)
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
    return OVERFLOW;
    Q->front->next=NULL;
    return OK;
}
Status enter_queue(LinkQueue*Q,QElemType e)
{
    QNode*new_node=(QNode*)malloc(sizeof(QNode));
    if(!new_node)
    return OVERFLOW;
    new_node->data=e;
    new_node->next=NULL;
    Q->rear->next=new_node;
    Q->rear=new_node;
    return OK;
}
Status de_queue(LinkQueue*Q,QElemType *e)
{
    if(Q->front==Q->rear)
    return ERROR;
    QNode*temp=Q->front->next;
    Q->front->next=temp->next;
    if(Q->rear==temp)
    Q->rear=Q->front;
    free(temp);
    return OK;
}