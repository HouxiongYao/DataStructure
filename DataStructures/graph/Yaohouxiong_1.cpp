#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
#define INT_MAX numeric_limits<int>::max()
typedef enum
{
    ERROR,
    OK
} Status;
class MGraph
{

public:
    int number_of_vertices;
    int number_of_arcs;
    vector<char> vertices;
    vector<vector<int>> matrix;
    MGraph()
    {
        number_of_vertices = 0;
        number_of_arcs = 0;
    }

    Status insert_vex(char vertex)
    {
        auto index = find(vertices.begin(), vertices.end(), vertex);
        if (index == vertices.end())
        {
            vertices.push_back(vertex);
            number_of_vertices++;
            matrix.push_back(vector<int>(number_of_vertices, INT_MAX));
            for (int i = 0; i < number_of_vertices; i++)
            {
                matrix[i].push_back(INT_MAX);
            }
            return OK;
        }
        return ERROR;
    }
    Status delete_vex(char vertex)
    {
        auto index = find(vertices.begin(), vertices.end(), vertex);
        if (index != vertices.end())
        {
            int idx = distance(vertices.begin(), index);
            for (int i = 0; i < number_of_vertices; i++)
            {
                if (matrix[idx][i] != INT_MAX)
                {
                    number_of_arcs--;
                }
            }
            matrix.erase(matrix.begin() + idx);
            number_of_vertices--;
            for (int i = 0; i < number_of_vertices; i++)
            {
                if (matrix[i][idx] != INT_MAX)
                    number_of_arcs--;
                matrix[i].erase(matrix[i].begin() + idx);
            }
            return OK;
        }
        return ERROR;
    }
    Status insert_arc(char vex_from, char vex_to, int weight)
    {
        auto idx_from = find(vertices.begin(), vertices.end(), vex_from);
        auto idx_to = find(vertices.begin(), vertices.end(), vex_to);
        if (idx_from != vertices.end() && idx_to != vertices.end() && idx_from != idx_to)
        {
            int from = distance(vertices.begin(), idx_from);
            int to = distance(vertices.begin(), idx_to);
            matrix[from][to] = weight;
            number_of_arcs++;
            return OK;
        }
        return ERROR;
    }
    Status delete_arc(int vex_from, int vex_to)
    {
        auto idx_from = find(vertices.begin(), vertices.end(), vex_from);
        auto idx_to = find(vertices.begin(), vertices.end(), vex_to);
        if (idx_from != vertices.end() && idx_to != vertices.end() && idx_from != idx_to)
        {
            int from = distance(vertices.begin(), idx_from);
            int to = distance(vertices.begin(), idx_to);
            matrix[from][to] = INT_MAX;
            number_of_arcs--;
            return OK;
        }
        return ERROR;
    }
    void print_adjacency_matrix()
    {
        cout << "Adjacency Matrix:" << endl;
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
