#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
#define INT_MAX numeric_limits<int>::max()
typedef enum
{
    ERROR, // 错误状态
    OK     // 正常状态
} Status;

class MGraph
{
public:
    int number_of_vertices;     // 顶点数量
    int number_of_arcs;         // 弧数量
    vector<char> vertices;      // 顶点集合
    vector<vector<int>> matrix; // 邻接矩阵

    MGraph()
    {
        number_of_vertices = 0; // 初始化顶点数量为0
        number_of_arcs = 0;     // 初始化弧数量为0
    }

    Status insert_vex(char vertex)
    {
        auto index = find(vertices.begin(), vertices.end(), vertex); // 查找顶点是否已存在
        if (index == vertices.end())
        {
            vertices.push_back(vertex);                                 // 将顶点添加到顶点集合
            number_of_vertices++;                                       // 增加顶点数量
            matrix.push_back(vector<int>(number_of_vertices, INT_MAX)); // 添加一行INF值到邻接矩阵
            for (int i = 0; i < number_of_vertices; i++)
            {
                matrix[i].push_back(INT_MAX); // 添加一列INF值到邻接矩阵
            }
            return OK; // 操作成功
        }
        return ERROR; // 顶点已存在，操作失败
    }

    Status delete_vex(char vertex)
    {
        if (vertices.empty())
            return ERROR;
        auto index = find(vertices.begin(), vertices.end(), vertex); // 查找顶点是否存在
        if (index != vertices.end())
        {
            int idx = distance(vertices.begin(), index); // 获取顶点索引
            for (int i = 0; i < number_of_vertices; i++)
            {
                if (matrix[idx][i] != INT_MAX)
                {
                    number_of_arcs--; // 删除顶点时减少与该顶点相关的弧数量
                }
            }
            matrix.erase(matrix.begin() + idx); // 删除邻接矩阵中的该行
            number_of_vertices--;               // 减少顶点数量
            for (int i = 0; i < number_of_vertices; i++)
            {
                if (matrix[i][idx] != INT_MAX)
                    number_of_arcs--;                     // 删除顶点时减少与该顶点相关的弧数量
                matrix[i].erase(matrix[i].begin() + idx); // 删除邻接矩阵中的该列
            }
            return OK; // 操作成功
        }
        return ERROR; // 顶点不存在，操作失败
    }

    Status insert_arc(char vex_from, char vex_to, int weight)
    {
        auto idx_from = find(vertices.begin(), vertices.end(), vex_from); // 查找起始顶点
        auto idx_to = find(vertices.begin(), vertices.end(), vex_to);     // 查找终止顶点
        if (idx_from != vertices.end() && idx_to != vertices.end() && idx_from != idx_to)
        {
            int from = distance(vertices.begin(), idx_from); // 获取起始顶点索引
            int to = distance(vertices.begin(), idx_to);     // 获取终止顶点索引
            matrix[from][to] = weight;                       // 设置邻接矩阵中的权重值
            number_of_arcs++;                                // 增加弧数量
            return OK;                                       // 操作成功
        }
        return ERROR; // 顶点不存在或起始终止顶点相同，操作失败
    }

    Status delete_arc(int vex_from, int vex_to)
    {
        if (vertices.empty())
            return ERROR;
        auto idx_from = find(vertices.begin(), vertices.end(), vex_from); // 查找起始顶点
        auto idx_to = find(vertices.begin(), vertices.end(), vex_to);     // 查找终止顶点
        if (idx_from != vertices.end() && idx_to != vertices.end() && idx_from != idx_to)
        {
            int from = distance(vertices.begin(), idx_from); // 获取起始顶点索引
            int to = distance(vertices.begin(), idx_to);     // 获取终止顶点索引
            matrix[from][to] = INT_MAX;                      // 将邻接矩阵中的权重值设置为INF
            number_of_arcs--;                                // 减少弧数量
            return OK;                                       // 操作成功
        }
        return ERROR; // 顶点不存在或起始终止顶点相同，操作失败
    }

    void print_adjacency_matrix()
    {
        cout << "邻接矩阵:" << endl;
        for (int i = 0; i < number_of_vertices; i++)
        {
            for (int j = 0; j < number_of_vertices; j++)
            {
                if (matrix[i][j] == INT_MAX)
                {
                    cout << "INF ";
                }
                else
                {
                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    MGraph graph; // Create a graph with 5 vertices

    // Insert vertices
    graph.insert_vex('A');
    graph.insert_vex('B');
    graph.insert_vex('C');
    graph.insert_vex('D');
    graph.insert_vex('E');

    // Insert arcs
    graph.insert_arc('A', 'B', 1);
    graph.insert_arc('B', 'C', 2);
    graph.insert_arc('C', 'A', 3);
    graph.insert_arc('D', 'A', 4);
    graph.insert_arc('E', 'D', 5);

    // Print the adjacency matrix
    graph.print_adjacency_matrix();

    // Print the number of vertices and arcs
    cout << "Number of vertices: " << graph.number_of_vertices << endl;
    cout << "Number of arcs: " << graph.number_of_arcs << endl;

    // Delete a vertex and its incident arcs
    graph.delete_vex('A');

    // Print the updated adjacency matrix
    graph.print_adjacency_matrix();

    // Print the updated number of vertices and arcs
    cout << "Number of vertices after deletion: " << graph.number_of_vertices << endl;
    cout << "Number of arcs after deletion: " << graph.number_of_arcs << endl;
    system("pause");
    return 0;
}
