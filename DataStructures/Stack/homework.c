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
                printf("ջ������\n");
                system("pause");
                return 0;
        }
        printf("������e\n");
        scanf("%d",&e);
        if(e!=-1)
        {
            *S.top++=e;
        }
        else
        {
            if(S.top==S.base)
            {
                printf("ջ�գ�");
                system("pause");
                return 0;
            }
            int top_e;
            top_e=*(--S.top);
            printf("��ǰջ����ֵ��%d\n",top_e);
        }
    }
    return 0;
}