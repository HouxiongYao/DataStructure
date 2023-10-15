#include"stdlib.h"
#include"stdio.h"
#define MAXSIZE 100
typedef int SElemType ;
typedef enum {
    OVERFLOW,
    OK,
    ERROR,
    INVALID_STACK_NUM
} Status;
typedef struct 
{
    int top[2],bot[2];
    SElemType*V;
    int m;
}DblStack;
Status init(DblStack*s);
Status destroy(DblStack*s);
Status pop(DblStack*s,int stack_num,SElemType*e);
Status push(DblStack *s, int stack_num, SElemType e);
Status isEmpty(DblStack*s,int stack_num);
Status isFilled(DblStack*s);
Status init(DblStack*s)
{
    s->V=(SElemType*)malloc(MAXSIZE*sizeof(SElemType));
    if(!s->V)
    return OVERFLOW;
    s->m=MAXSIZE;
    s->top[0]=-1;
    s->bot[0]=s->top[0];
    s->top[1]=s->m;
    s->bot[1]=s->top[1];
    return OK;
}
Status isEmpty(DblStack *s, int stack_num) {
    switch(stack_num) 
    {
    case 0:
        return s->top[0] == -1 ? OK : ERROR;
    case 1:
        return s->top[1] == MAXSIZE ? OK : ERROR;
    
    default: return INVALID_STACK_NUM; 
    }
}

Status isFilled(DblStack*s)
{
    return (s->top[0]+1==s->top[1])?OK:ERROR;
}
Status push(DblStack *s, int stack_num, SElemType e) {
    if (isFilled(s)==OK) {
        return ERROR; 
    }

    switch (stack_num) {
        case 0:
            s->V[++s->top[0]] = e;
            return OK;
        case 1:
            s->V[--s->top[1]] = e;
            return OK;
        default:
            return INVALID_STACK_NUM;
    }
}
Status pop(DblStack *s, int stack_num, SElemType *e) {
    if (isEmpty(s, stack_num)==OK) {
        return ERROR;
    }

    switch (stack_num) {
        case 0:
            *e = s->V[s->top[0]--];
            return OK;
        case 1:
            *e = s->V[s->top[1]++];
            return OK;
        default:
            return INVALID_STACK_NUM;
    }
}

Status destroy(DblStack*s)
{
    if(s)
    {
        free(s->V);
        s->V=NULL;
        s->m = 0;
        s->top[0] = -1;
        s->bot[0] = s->top[0];
        s->top[1] = 0;
        s->bot[1] = s->top[1];
        s=NULL;
        return OK;
    }
    return ERROR;
}
int main() {
    DblStack s;
    SElemType e;

    // 初始化双栈
    if (init(&s) == OK) {
        printf("Initialization successful!\n");
    } else {
        printf("Initialization failed!\n");
        return 1;
    }

    // 测试push操作
    if (push(&s, 0, 10) == OK) {
        printf("Pushed 10 to Stack[0] successfully!\n");
    }

    if (push(&s, 1, 20) == OK) {
        printf("Pushed 20 to Stack[1] successfully!\n");
    }

    // 测试pop操作
    if (pop(&s, 0, &e) == OK) {
        printf("Popped from Stack[0]: %d\n", e);
    }

    if (pop(&s, 1, &e) == OK) {
        printf("Popped from Stack[1]: %d\n", e);
    }

    // 测试isEmpty操作
    if (isEmpty(&s, 0) == OK) {
        printf("Stack[0] is empty!\n");
    } else {
        printf("Stack[0] is not empty!\n");
    }

    if (isEmpty(&s, 1) == OK) {
        printf("Stack[1] is empty!\n");
    } else {
        printf("Stack[1] is not empty!\n");
    }

    // 销毁双栈
    if (destroy(&s) == OK) {
        printf("DblStack destroyed successfully!\n");
    } else {
        printf("Failed to destroy DblStack!\n");
    }
    getchar();
    return 0;
}
