#include "stdio.h"
#include "stdlib.h"
#include <stack>
#include <vector>
using namespace std;
// 定义二叉树的节点结构体
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// 定义队列的节点结构体
typedef struct QueueNode {
  Node* treeNode;
  struct QueueNode* next;
} QueueNode;

// 函数声明
Node* createNode(char data);
//遍历算法的递归描述
void preOrderTraversal(Node* root);
void inOrderTraversal(Node* root); 
void postOrderTraversal(Node* root);
//遍历算法的非递归描述
void enqueue(QueueNode** front, QueueNode** rear, Node* treeNode);
Node* dequeue(QueueNode** front, QueueNode** rear);
void levelOrderTraversal(Node* root);
void pre_order(Node* root);
void in_order(Node* root);
void post_order(Node* root);
int main() {
    // 构建一个简单的二叉树
    Node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');

    // 先序遍历
    printf("Pre-order Traversal: ");
    pre_order(root);
    printf("\n");

    // 中序遍历
    printf("In-order Traversal: ");
    in_order(root);
    printf("\n");

    // 后序遍历
    printf("Post-order Traversal: ");
    post_order(root);
    printf("\n");

    // 层级遍历
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");
    system("pause");
    return 0;
}

// 函数定义
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrderTraversal(Node* root) {
    if(root!=NULL)
    {
        printf("%c",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(Node* root) {
    if(root != NULL) {
        inOrderTraversal(root->left);  // 递归遍历左子树
        printf("%c ", root->data); // 访问根节点
        inOrderTraversal(root->right); // 递归遍历右子树
    }
}


void postOrderTraversal(Node* root) {
    if(root != NULL) {
        postOrderTraversal(root->left);  // 递归遍历左子树
        postOrderTraversal(root->right); // 递归遍历右子树
        printf("%c ", root->data); // 访问根节点
    }
}

void enqueue(QueueNode** front, QueueNode** rear, Node* treeNode) {
  QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
  if(newNode == NULL) {
    fprintf(stderr, "Unable to allocate memory for new queue node\n");
    exit(-1);
  }
  newNode->treeNode = treeNode;
  newNode->next = NULL;

  if(*front == NULL) {
    *front = *rear = newNode;
  } else {
    (*rear)->next = newNode;
    *rear = newNode;
  }
}

Node* dequeue(QueueNode** front, QueueNode** rear) {
  if(*front == NULL) {
    fprintf(stderr, "Queue is empty\n");
    return NULL;
  }

  QueueNode* tempNode = *front;
  Node* treeNode = tempNode->treeNode;

  *front = (*front)->next;
  if(*front == NULL) {
    *rear = NULL;
  }
  free(tempNode);

  return treeNode;
}

void levelOrderTraversal(Node* root) {
    QueueNode* front=NULL;
    QueueNode*rear=NULL;
    enqueue(&front,&rear,root);
    while(front!=NULL)
    {
        Node*cur=dequeue(&front,&rear);
        printf("%c",cur->data);
        if(cur->left!=NULL)
        {
            enqueue(&front,&rear,cur->left);
        }
        if(cur->right!=NULL)
        {
            enqueue(&front,&rear,cur->right);
        }
    }
}
void pre_order(Node* root)
{
  stack<Node*> my_stack;
  Node*cur=root;
  while (cur||!my_stack.empty())
  {
      while(cur)
      {
        printf("%c",cur->data);
        my_stack.push(cur);
        cur=cur->left;
      }
      cur=my_stack.top();
      my_stack.pop();
      cur=cur->right;
  } 
}
void in_order(Node* root)
{
    stack<Node*> my_stack;
  Node*cur=root;
  while (cur||!my_stack.empty())
  {
      while(cur)
      {

        my_stack.push(cur);
        cur=cur->left;
      }
      cur=my_stack.top();
      my_stack.pop();
      printf("%c",cur->data);
      cur=cur->right;
  }
}
void post_order(Node* root)
{
    stack<Node*> my_stack;
    Node*cur=root;
    Node* last_visited = nullptr;
    while (cur||!my_stack.empty())
    {
      while (cur)
      {
        my_stack.push(cur);
        cur=cur->left;
      }
      Node*top_node=my_stack.top();
      if(top_node->right==nullptr||top_node->right==last_visited)
      {
          printf("%c",top_node->data);
          my_stack.pop();
          last_visited=top_node;
      }
      else
      {
        cur=top_node->right;
      }
    }
}