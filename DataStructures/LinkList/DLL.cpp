# include "stdio.h"
# include<iostream>
typedef enum{
    OK,
    ERROR
}Status;
typedef int ElemType;
typedef struct DLLNode
{
    ElemType data;
    DLLNode*pre;
    DLLNode*next;
}DLLNode,*DLList;
Status init(DLList*head);
Status destory(DLList*head);
Status locate_elem(DLList*head,ElemType e,DLLNode**target);
Status get_elem(DLList*head,ElemType e,int target_index);
Status list_insert(DLList* head,int target_index,ElemType e);
Status list_delete(DLList* head,int target_index);
Status list_create_head(DLList*head,int n);
Status list_create_tail(DLList*head,int n);
Status print_list(DLList*head,int n);
Status init(DLList*head)
{
    *head=new DLLNode;
    if (*head==NULL)
    {
        return ERROR;
    }
    (* head)->next=NULL;
    (*head)->pre=NULL;
    return OK;
}
Status destory(DLList*head)
{
    if(head==NULL||*head==NULL)
    {
        return ERROR;
    }
    DLLNode* current;
    DLLNode* next;
    for(current=*head;current!=NULL;next=current->next,delete current,current=next);
    *head=NULL;
    return OK;
}
Status locate_elem(DLList*head,ElemType e,DLLNode**target)
{
    if(head==NULL||*head==NULL)
    return ERROR;
    DLLNode*current;
    for(current=(*head)->next;current!=NULL;current=current->next)
    {
        if(current->data==e)
        {
            *target=current;
        return OK;
        }
    }
}
Status get_elem(DLList*head,int* e,int target_index)
{
    if(head==NULL||*head==NULL||target_index<0)
    return ERROR;
    DLLNode* current;
    int current_index=0;
    for(current=(*head)->next;current!=NULL;current=current->next,current_index++)
    {
        if(current_index==target_index)
        {
            *e=current->data;
            return OK;
        }
    }
    return ERROR;
}
Status list_insert(DLList* head,int target_index,ElemType e)
{
    if(head==NULL||*head==NULL||target_index<0)
    return ERROR;
    DLLNode* current;
    int current_index=0;
    for(current=(*head)->next;current!=NULL&&current_index<target_index;current=current->next,current_index++);
    if (current==NULL)
    {
        printf("index out of range!\n");
        return ERROR;
    }
    
    DLLNode*new_node=new DLLNode;

    new_node->data=e;
    
    new_node->pre=current->pre;
    new_node->pre->next=new_node;
    current->pre=new_node;
    new_node->next=current;
    return OK;
}
Status list_delete(DLList* head,int target_index)
{
    if(head==NULL||*head==NULL||target_index<0)
    return ERROR;
    DLLNode* current;
    int current_index=0;
    for(current=(*head)->next;current!=NULL&&current_index<target_index;current=current->next,current_index++);
    if(current==NULL||current_index>target_index)
    return ERROR;
    if(current->next)
    current->next->pre=current->pre;
    current->pre->next=current->next; 
    return OK;
}
Status list_create_head(DLList*head,int n)
{
    init(head);
    for(int i=0;i<n;i++)
    {
        DLLNode*new_node=new DLLNode;
        if(new_node==NULL)
        return ERROR;
            printf("please enter the value of element %d\n",n-i-1);
            while(!scanf("%d",&new_node->data))
            {
                printf("error,enter again\n");
                    while (getchar()!='\n');
            }
            new_node->next=(*head)->next;
            if((*head)->next)
            (*head)->next->pre=new_node;
            new_node->pre=(*head);
            (*head)->next=new_node;
    }
    return OK;
}
Status list_create_tail(DLList*head,int n)
{
    init(head);
    DLLNode*tail=new DLLNode;
    tail->next=NULL;
    tail->pre=NULL;
        for(int i=0;i<n;i++)
    {
        DLLNode*new_node=new DLLNode;
        if(new_node==NULL)
        return ERROR;
        printf("please enter the value of element %d\n",i);
          while(!scanf("%d",&new_node->data))
            {
                printf("error,enter again\n");
                    while (getchar()!='\n');
            }
            new_node->next=NULL;
            if(tail->next)
            {
            new_node->pre=tail->next;
            tail->next->next=new_node;
            }
            else
            {
                new_node->pre=*head;
                (*head)->next=new_node;
            }
            tail->next=new_node;
    }
    return OK;
}
Status print_list(DLList*head)
{
    if(head==NULL||*head==NULL)
    return ERROR;
    DLLNode*current;
    int current_idx=0;
    printf("list is here:\n");
    for(current=(*head)->next;current!=NULL;printf("%d  %d\n",current_idx,current->data),
    current=current->next,current_idx++);
    return OK;
}
int main() {
    DLList list = NULL;

    // 测试初始化
    if (init(&list) == OK) {
        printf("Initialization successful.\n");
    } else {
        printf("Initialization failed.\n");
    }

    // 测试从头部创建列表
    printf("\nCreating list from head with 3 elements:\n");
    list_create_head(&list, 3);
    print_list(&list);

    // 测试从尾部创建列表
    printf("\nCreating list from tail with 3 elements:\n");
    list_create_tail(&list, 3);
    print_list(&list);

    // 测试插入元素
    printf("\nInserting element 999 at position 2:\n");
    list_insert(&list, 2, 999);
    print_list(&list);

    // 测试删除元素
    printf("\nDeleting element at position 2:\n");
    list_delete(&list, 2);
    print_list(&list);

    // 测试查找元素
    DLLNode* target = NULL;
    if (locate_elem(&list, 2, &target) == OK) {
        printf("\nElement 2 found.\n");
    } else {
        printf("\nElement 2 not found.\n");
    }

    // 测试获取元素
    int value;
    if (get_elem(&list, &value, 1) == OK) {
        printf("\nElement at position 1 is: %d\n", value);
    } else {
        printf("\nFailed to get element at position 1.\n");
    }

    // 测试销毁列表
    if (destory(&list) == OK) {
        printf("\nList destroyed successfully.\n");
    } else {
        printf("\nFailed to destroy list.\n");
    }

    system("pause");
    return 0;
}
