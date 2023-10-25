# include "stdlib.h"
# include "stdio.h"
# define MAX_TREE_SIZE 100
typedef int TElemType;
//双亲表示法
typedef struct{
    TElemType data;
    int parent;
}PTNode;
//树的结构
typedef struct 
{
    PTNode nodes[MAX_TREE_SIZE];
    int r,n;//根的位置和结点数
}PTree;
//孩子表示法
//孩子节点
typedef struct ChildNode
{
    int childIndex;
    struct ChildNdode* next;
}ChildNdode;
//定义树的节点
typedef struct Treenode
{
    char data;
    struct ChildNode* firstChiild;
}TreeNode;
//定义树
typedef struct 
{
    TreeNode node[MAX_TREE_SIZE];
    int r,n;
}Tree;
//孩子兄弟表示法
typedef struct CSNode
{
    char data;
    struct CSNode* firstChild;//第一个孩子节点的指针
    struct CSNode* nextSibling;//右侧兄弟节点的指针

}CSNode,*CSTree;
//二叉树的链式存储
typedef struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
}Node;
//二叉链表
typedef struct TriNode
{
    char data;
    struct TriNode* left;
    struct TriNode* right;
    struct TriNode* parent;
}TriNode;


