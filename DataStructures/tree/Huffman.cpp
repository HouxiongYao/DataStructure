#include <iostream>
#include <string.h>
using namespace std;
typedef struct HTNode
{
    int weight;
    int parent, lchild, rchild;
    HTNode()
    {
        parent = 0;
        lchild = 0;
        rchild = 0;
    }
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;
void Select(HuffmanTree HT, int i, int &s1, int &s2)
{
    int min1 = -1;
    int min2 = -1;
    for (int j = 1; j <= i; j++)
    {
        if (HT[j].parent == 0)
        {
            if (min1 == -1 || HT[j].weight < HT[min1].weight)
            {
                min2 = min1;
                min1 = j;
            }
            else if (min2 == -1 || HT[j].weight < HT[min2].weight)
            {
                min2 = j;
            }
        }
    }
    s1 = min1;
    s2 = min2;
}

void CreateHuffmanTree(HuffmanTree &HT, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    HT = new HTNode[m + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight;
    }
    for (int i = n + 1; i <= m; i++)
    {
        int s1;
        int s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}
void creat_huffmantree_code(HuffmanTree HT, HuffmanCode &HC, int n)
{
    HC = new char *[n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';
    for (int i = 1; i <= n; i++)
    {
        int start = n - 1;
        int c = i;
        int f = HT[c].parent;
        while (f != 0)
        {
            start--;
            if (c == HT[f].lchild)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete cd;
}
int main()
{
    int n = 4; // Change this to the number of nodes in your Huffman tree.

    // Create a Huffman Tree
    HuffmanTree HT;
    CreateHuffmanTree(HT, n);

    // Create Huffman Codes
    HuffmanCode HC;
    creat_huffmantree_code(HT, HC, n);

    // Display Huffman Codes
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " Weight: " << HT[i].weight << " Code: " << HC[i] << endl;
    }

    // Free allocated memory
    for (int i = 1; i <= n; i++)
    {
        delete[] HC[i];
    }
    delete[] HC;
    delete[] HT;
    system("pause");
    return 0;
}
