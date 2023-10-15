#include <stdlib.h>

#define STACK_INT_SIZE 100
#define STACK_INCREMENT 100

typedef int elemType;
typedef struct Stack {
    elemType *base;     // 栈底指针
    elemType *top;      // 栈顶指针
    int stackSize;      // 当前分配的存储容量
} SqStack;

typedef enum {
    OVERFLOW,
    OK,
    ERROR
} Status;

Status init_stack(SqStack *s) {
    s->base = (elemType *) malloc(STACK_INT_SIZE *sizeof (elemType));
    if(!s->base) {
        return OVERFLOW;
    }
    s->top = s->base;
    s->stackSize = STACK_INT_SIZE;
    return OK;
}

Status get_top(SqStack s, elemType *e) {
    if (s.top == s.base) {
        return ERROR;
    }
    *e = *(s.top - 1);
    return OK;
}

Status push(SqStack *s, elemType e) {
    if (s->top - s->base >= s->stackSize) {
        s->base = (elemType *) realloc(s->base, ((s->stackSize + STACK_INCREMENT) * sizeof (elemType)));
        if (!s->base) {
            return OVERFLOW;
        }
        s->top = s->base + s->stackSize;
        s->stackSize += STACK_INCREMENT;
    }
    *s->top++ = e;
    return OK;
}

Status pop(SqStack *s, elemType *e) {
    if (s->top == s->base) {
        return ERROR;
    }
    *e = *(--s->top);
    return OK;
}