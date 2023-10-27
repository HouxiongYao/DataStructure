# include<iostream>
# include<algorithm>
using namespace std;
typedef struct CSNode
{
    int data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
int depth(CSNode*T)
{
    if(T==NULL)
    return 0;
    CSNode*p=T->firstchild;
    int max_depth=0;
    while (p!=NULL)
    {
        int child_dep=0;
        child_dep=depth(p);
        max_depth=max(max_depth,child_dep);
        p=p->nextsibling;
    }
    return max_depth+1;
}
int main() {
    // Create a sample tree
    CSTree root = new CSNode{1, NULL, NULL};
    root->firstchild = new CSNode{2, NULL, NULL};
    root->firstchild->nextsibling = new CSNode{3, NULL, NULL};
    root->firstchild->firstchild = new CSNode{4, NULL, NULL};
    root->firstchild->firstchild->nextsibling = new CSNode{5, NULL, NULL};
    root->firstchild->nextsibling->firstchild = new CSNode{6, NULL, NULL};

    // Calculate and print the depth of the tree
    int treeDepth = depth(root);
    cout << "Depth of the tree is: " << treeDepth << endl;

    // Clean up memory (not shown in your original code)
    delete root->firstchild->nextsibling->firstchild;
    delete root->firstchild->firstchild->nextsibling;
    delete root->firstchild->firstchild;
    delete root->firstchild->nextsibling;
    delete root->firstchild;
    delete root;
    system("pause");
    return 0;
}