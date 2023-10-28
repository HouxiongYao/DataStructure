# include<iostream>
# define MAX_VERTEX_NUM 20 // 图中最大的顶点个数

typedef struct ArcCell {
    int adj;  // 顶点关系类型。对无权图，用1或0表示相邻否；对带权图，则为权值类型，对带权图，则为权值
    // InfoType *info;
} ArcCell, AdjMatrix;

typedef char VertexType; // 顶点类型应由用户定义

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点向量
    AdjMatrix arcs; // 邻接矩阵
    int vexnum, arcnum; // 图的当前顶点数和弧数
} MGraph;


// 用邻接表表示法创建无向图
typedef struct Arcnode {
    int adjvex; // 该弧所指向的顶点的位置
    struct Arcnode* nextarc; // 指向下一条弧的指针
} Arcnode;

typedef struct Vnode {
    VertexType data; // 顶点信息
    Arcnode* firstarc; // 指向第一条依附该顶点的弧的指针
} Vnode, AdjList[MAX_VERTEX_NUM];

typedef struct
{   AdjList vertices;
    int vexnum, arcnum;   //顶点及弧的数目
} ALGraph;