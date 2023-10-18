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
    return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;//为何+MAXSIZE，因为rear可能小于front。
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
int main() {
    SqQueue myQueue;
    QElemType element;

    // 初始化队列
    Status initStatus = init_queue(&myQueue);
    if (initStatus != OK) 
    {
        printf("Queue initialization failed\n");
        return 1;
    }

    // 向队列中添加元素
    for (int i = 1; i <= MAXSIZE; i++) {
        Status enterStatus = enter_queue(&myQueue, i * 10);
        if (enterStatus != OK) {
            printf("Queue is full. Cannot enter element: %d\n", i * 10);
            break;
        }
    }

    // 计算队列的长度
    int length = Queue_length(&myQueue);
    printf("Queue length: %d\n", length);

    // 出队并打印元素
    while (de_queue(&myQueue, &element) == OK) {
        printf("Dequeued: %d\n", element);
    }

    // 尝试再次出队应该返回错误
    Status deQueueStatus = de_queue(&myQueue, &element);
    if (deQueueStatus == ERROR) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeue failed\n");
    }

    free(myQueue.base);  // 释放分配的内存
    system("pause");
    return 0;
}