#include<iostream>
#include<stdio.h>
using namespace std;
typedef int TElemType;
typedef enum
{
    Link,Thread
}PointerTag;
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode*lchild,*rchild;
    PointerTag LTag,RTag;
    
}BiThrNode,*BiThrTree;
BiThrTree pre=NULL;
BiThrTree newNode(TElemType data)
{
    BiThrNode* node=new BiThrNode;
    if(!node)
    {
        cout<<"Memory allocation faild"<<endl;
        exit(1);
    }
    node->data=data;
    node->lchild = node->rchild = NULL;
    node->LTag = node->RTag = Link;
    return node;
}
void inOrderThreading(BiThrTree node) 
{
    if(node)
    {
        inOrderThreading(node->lchild);
        if(!node->lchild)
        {
            node->LTag=Thread;
            node->lchild=pre;
        }
        if(pre&&!pre->rchild)
        {
            pre->RTag=Thread;
            pre->rchild=node;
        }
        pre=node;
        inOrderThreading(node->rchild);
    }
}
void InOrderTraverse(BiThrTree T) {
    BiThrTree p=T;
    while(p&&p->LTag==Link)
    {
        p=p->lchild;
    }
    while(p)
    {
        printf("%d\n",p->data);
        if(p->RTag==Thread)
        {
            p=p->rchild;
        }
        else
        {
            p=p->rchild;
            while(p&&p->LTag==Link)
            {
                p=p->lchild;
            }
        }
        printf("\n");
    }
}
BiThrTree buildTree() {
    // 此函数中创建一个简单的二叉树以示例，实际应用中可能需要更复杂的逻辑
    BiThrTree root = newNode(1);
    root->lchild = newNode(2);
    root->rchild = newNode(3);
    root->lchild->lchild = newNode(4);
    root->lchild->rchild = newNode(5);
    root->rchild->rchild = newNode(6);
    return root;
}

int main() {
    BiThrTree root = buildTree();
    inOrderThreading(root);
    InOrderTraverse(root);
    system("pause");
    return 0;
}