#include"stdlib.h"
#include"stdio.h"
#define MAXSIZE 10
typedef struct Stack
{
    int *base;
    int *top;
    int stack_size;
} SqStack;
int main()
{
    SqStack S;
    S.base=(int*)malloc(MAXSIZE*sizeof(int));

    S.top=S.base;
    S.stack_size=MAXSIZE;
    int e;
    while(1)
    {

        if (S.top-S.base>=S.stack_size)
        {
                printf("栈已满！\n");
                system("pause");
                return 0;
        }
        printf("请输入e\n");
        scanf("%d",&e);
        if(e!=-1)
        {
            *S.top++=e;
        }
        else
        {
            if(S.top==S.base)
            {
                printf("栈空！");
                system("pause");
                return 0;
            }
            int top_e;
            top_e=*(--S.top);
            printf("当前栈顶的值是%d\n",top_e);
        }
    }
    return 0;
}