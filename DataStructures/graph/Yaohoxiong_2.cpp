#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

typedef enum
{
    ERROR, // 错误状态
    OK     // 正常状态
} Status;
typedef char VertexType; // 顶点类型

// 定义邻接表中的弧节点
typedef struct Arcnode
{
    int adjvex;              // 该弧所指向的顶点的位置
    struct Arcnode *nextarc; // 指向下一条弧的指针
} Arcnode;

// 定义顶点节点
typedef struct Vnode
{
    VertexType data;   // 顶点信息
    Arcnode *firstarc; // 指向第一条依附该顶点的弧的指针
} Vnode;

// 定义邻接表图类
class ALgraph
{
public:
    vector<Vnode *> vertices; // 存储顶点的向量
    int number_of_vertices;   // 顶点数量
    int number_of_arcs;       // 弧的数量

    // 构造函数，初始化顶点和弧的数量
    ALgraph() : number_of_arcs(0), number_of_vertices(0) {}

    // 插入顶点
    Status insert_vex(VertexType vex)
    {
        for (int i = 0; i < number_of_vertices; i++)
        {
            if (vertices[i]->data == vex)
            {
                return ERROR; // 顶点已存在，插入失败
            }
        }

        // 创建新的顶点节点
        Vnode *new_vex_node = new Vnode;
        if (new_vex_node == NULL)
            return ERROR; // 内存分配失败

        new_vex_node->data = vex;
        new_vex_node->firstarc = NULL;
        vertices.push_back(new_vex_node); // 将新顶点添加到图中
        number_of_vertices++;
        return OK;
    }

    // 删除顶点
    Status delete_vex(VertexType vex)
    {
        if (vertices.empty() == true)
            return ERROR; // 图为空，删除失败

        int index = -1;
        for (int i = 0; i < number_of_vertices; i++)
        {
            if (vertices[i]->data == vex)
            {
                index = i;
            }
        }

        if (index == -1)
            return ERROR; // 顶点不存在，删除失败

        // 删除与该顶点相关的弧
        for (int i = 0; i < number_of_vertices; i++)
        {
            if (i != index)
            {
                delete_arc(vertices[i]->data, vex);
                delete_arc(vex, vertices[i]->data);
                Arcnode *arc = vertices[i]->firstarc;

                // 更新顶点位置信息
                while (arc != NULL && arc->adjvex > index)
                {
                    arc->adjvex--;
                    arc = arc->nextarc;
                }
            }
        }

        // 释放顶点内存
        delete vertices[index];
        vertices.erase(vertices.begin() + index);
        number_of_vertices--;
        return OK;
    }

    // 插入弧
    Status insert_arc(VertexType vex_from, VertexType vex_to)
    {
        for (int i = 0; i < number_of_vertices; i++)
        {
            if (vertices[i]->data == vex_from)
            {
                for (int j = 0; j < number_of_vertices; j++)
                {
                    if (vertices[j]->data == vex_to && i != j)
                    {
                        Arcnode *first_arcnode = vertices[i]->firstarc;

                        // 如果该顶点没有邻接的弧
                        if (first_arcnode == NULL)
                        {
                            Arcnode *new_arc_node = new Arcnode;
                            vertices[i]->firstarc = new_arc_node;
                            new_arc_node->adjvex = j;
                            new_arc_node->nextarc = NULL;
                            number_of_arcs++;
                            return OK;
                        }

                        // 寻找最后一个弧节点
                        while (first_arcnode->nextarc != NULL)
                        {
                            if (first_arcnode->adjvex == j)
                                return ERROR; // 弧已存在，插入失败
                            first_arcnode = first_arcnode->nextarc;
                        }

                        // 在最后添加新的弧节点
                        Arcnode *new_arc_node = new Arcnode;
                        first_arcnode->nextarc = new_arc_node;
                        new_arc_node->nextarc = NULL;
                        new_arc_node->adjvex = j;
                        number_of_arcs++;
                        return OK;
                    }
                }
                return ERROR; // 目标顶点不存在，插入失败
            }
        }
        return ERROR; // 起始顶点不存在，插入失败
    }

    // 删除弧
    Status delete_arc(VertexType vex_from, VertexType vex_to)
    {
        if (vertices.empty() == true)
            return ERROR; // 图为空，删除失败

        for (int i = 0; i < number_of_vertices; i++)
        {
            if (vertices[i]->data == vex_from)
            {
                for (int j = 0; j < number_of_vertices; j++)
                {
                    if (vertices[j]->data == vex_to && i != j)
                    {
                        Arcnode *first_arcnode = vertices[i]->firstarc;

                        if (first_arcnode == NULL)
                            return ERROR; // 弧不存在，删除失败

                        // 如果要删除的弧是第一个
                        if (first_arcnode->adjvex == j)
                        {
                            vertices[i]->firstarc = first_arcnode->nextarc;
                            delete first_arcnode;
                            number_of_arcs--;
                            return OK;
                        }

                        // 寻找要删除的弧
                        while (first_arcnode != NULL && first_arcnode->nextarc != NULL)
                        {
                            if (first_arcnode->nextarc->adjvex == j)
                            {
                                Arcnode *to_delete = first_arcnode->nextarc;
                                first_arcnode->nextarc = to_delete->nextarc;
                                delete to_delete;
                                number_of_arcs--;
                                return OK;
                            }
                            first_arcnode = first_arcnode->nextarc;
                        }
                        return ERROR; // 弧不存在，删除失败
                    }
                }
                return ERROR; // 目标顶点不存在，删除失败
            }
        }
        return ERROR; // 起始顶点不存在，删除失败
    }
};

int main()
{
    ALgraph graph;

    // 插入顶点
    graph.insert_vex('A');
    graph.insert_vex('B');
    graph.insert_vex('C');
    graph.insert_vex('D');

    // 插入边
    graph.insert_arc('A', 'B');
    graph.insert_arc('A', 'C');
    graph.insert_arc('B', 'D');
    graph.insert_arc('C', 'D');

    // 打印邻接表
    cout << "adj table" << endl;
    for (int i = 0; i < graph.number_of_vertices; i++)
    {
        Vnode *v = graph.vertices[i];
        cout << "vex" << v->data << " 's adj vex: ";
        Arcnode *arc = v->firstarc;
        while (arc != nullptr)
        {
            cout << graph.vertices[arc->adjvex]->data << " ";
            arc = arc->nextarc;
        }
        cout << endl;
    }

    // 删除边
     graph.delete_arc('A', 'C');

    // 删除顶点
    graph.delete_vex('B');

    // 重新打印邻接表
    cout << "adj table after delete " << endl;
    for (int i = 0; i < graph.number_of_vertices; i++)
    {
        Vnode *v = graph.vertices[i];
        cout << "vex " << v->data << "'s adj vex: ";
        Arcnode *arc = v->firstarc;
        while (arc != nullptr)
        {
            cout << graph.vertices[arc->adjvex]->data << " ";
            arc = arc->nextarc;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
