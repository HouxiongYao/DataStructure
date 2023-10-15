# include"stdlib.h"
# include"stdio.h"
typedef int ElemType;
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;
typedef enum {
    OVERFLOW,
    OK,
    ERROR,
    INVALID_STACK_NUM
} Status;
Status InitStack(LinkStack*s)
{
    s=NULL;
    return OK;
}
Status Push(LinkStack*s,ElemType e)
{
    StackNode*new_node=(StackNode*)malloc(sizeof(StackNode));
    new_node->next=(*s);
    new_node->data=e;
    (*s)=new_node;
    return OK;
}
Status Pop(LinkStack*s,ElemType*e)
{
    if((*s)==NULL)
    return ERROR;
    *e=(*s)->data;
    StackNode*p=(*s);
    (*s)=(*s)->next;
    free(p);
    return OK;

}
ElemType GetTop(LinkStack*s)
{
    if((*s)!=NULL)
    return (*s)->data;
    else
    return -1;
}
int main() {
    LinkStack stack;
    ElemType top_element;
    Status status;

    // 初始化栈
    status = InitStack(&stack);
    if (status != OK) {
        printf("初始化栈失败\n");
        return 1;
    }

    // 入栈操作
    for (int i = 1; i <= 5; i++) {
        status = Push(&stack, i * 10);
        if (status != OK) {
            printf("入栈失败\n");
            return 1;
        }
    }

    // 获取栈顶元素
    top_element = GetTop(&stack);
    if (top_element != -1&&stack!=NULL) {
        printf("栈顶元素是：%d\n", top_element);
    } else {
        printf("栈为空\n");
    }

    // 出栈操作
    for (int i = 0; i < 3; i++) {
        status = Pop(&stack, &top_element);
        if (status != OK) {
            printf("出栈失败\n");
            return 1;
        }
        printf("出栈元素：%d\n", top_element);
    }
    system("pause");
    return 0;
}