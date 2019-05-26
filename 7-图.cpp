// #include <iostream>
// #include <iomanip>
// using namespace std;

// const int MaxValue = 32767; //表示无穷大
// const int MaxVertices = 10; //最大顶点个数
// const int MaxEdges = 50;    //最大边数
// const int MaxSize = 50;
// typedef int DataType;
// typedef int EdgeType;
// bool Visited[MaxVertices];

// class Graph
// {
//     DataType VerticesList[MaxVertices];

//     int numberEdges, numberVertices;
//     int Edge[MaxVertices][MaxVertices];

// public:
//     Graph();                              //构造函数
//     void CreatEdge();                     //建图边
//     void CreatVertices(int num);          //建顶点
//     void dfsMatrix(int i, bool *visited); //深度优先遍历算法
//     void bfsMatrix(int i, bool *visited); //广度优先遍历算法
//     void print();
//     void dfsTraverse(); //深度优先搜索（非连通图）
//     void bfsTraverse(); //广度优先搜索（非连通图）　
// };

// Graph::Graph() //无权图的构造函数
// {
//     for (int i = 0; i < MaxVertices; i++) //初始化Edge数组
//         for (int j = 0; j < MaxVertices; j++)
//             Edge[i][j] = 0;
//     for (i = 0; i < MaxVertices; i++)
//         Visited[i] = false;
//     numberVertices = 0; //初始化 numberVertices
// }

// void Graph::CreatVertices(int num)
// {
//     numberVertices = num;
//     int i = 0;
//     DataType n;
//     while (i < numberVertices)
//     {
//         cin >> n;
//         VerticesList[i] = n;
//         i++;
//     }
// }

// void Graph::CreatEdge() //建立无向无权图
// {
//     int i, j, x = 0, y = 0; //用i,j,weight保存一条边的起点、终点序号和权值
//     char c1, c2, c3, c4;    //用来保存输入的字符
//     cout << "请输入边(两条边之间用b隔开，以#结束，如输入0 1 b 1 2 #)：" << endl;
//     do
//     {
//         cin >> c1 >> i >> c2 >> j >> c3;

//         Edge[i][j] = 1;
//         Edge[j][i] = 1; //置相应的对称元素为1
//         cin >> c4;      //读入逗号或右花括号
//         if (c4 == '#')
//             break; //边集处理完毕，退出循环
//     } while (1);
// }

// void Graph ::dfsMatrix(int i, bool *visited) //（连通图的深度优先遍历）
// {                                            //从初始点vi出发深度优先搜索由邻接矩阵表示的图
//     cout << i << ' ';
//     //假定访问顶点vi以输出该顶点的序号代之
//     visited[i] = true; //标记vi已被访问过
//     for (int j = 0; j < numberVertices; j++)
//         //依次搜索v的每个邻接点
//         if (Edge[i][j] != 0 && Edge[i][j] != MaxValue && !visited[j])
//             //若vi的一个有效邻接点vj未被访问过，则从vj出发进行递归调用
//             dfsMatrix(j, visited);
// }

// int main()
// {
//     Graph g, g1;
//     DataType m;
//     int k;
//     cin >> m;
//     g.CreatVertices(m);
//     g.CreatEdge();
//     g.dfsMatrix(0, &Visited[0]);
//     cout << endl;
//     return 0;
// }

// （2） //有向有全图广度优先遍历(邻接矩阵法）
#include <iostream>
#include <iomanip>
    using namespace std;

const int MaxValue = 32767; //表示无穷大
const int MaxVertices = 10; //最大顶点个数
const int MaxEdges = 50;    //最大边数
const int MaxSize = 50;
typedef int DataType;
typedef int EdgeType;
typedef int WeightType;

bool Visited[MaxVertices];

class Graph
{
    DataType VerticesList[MaxVertices];
    int numberEdges, numberVertices;
    int Edge[MaxVertices][MaxVertices];

public:
    Graph();                    //构造函数
    void CreateEdge();          //建立边
    void CreateVertices(int n); //建立顶点
    //void bfsMatrix( int i,  bool* visited);//广度优先遍历算法
    void bfsTraverse(); //广度优先搜索（非连通图）
    void bfsMatrix(int i, bool *visited);
};

Graph::Graph() //有权图的构造函数
{
    for (int i = 0; i < MaxVertices; i++) //初始化Edge数组
        for (int j = 0; j < MaxVertices; j++)
            if (i == j)
                Edge[i][j] = 0;
            else
                Edge[i][j] = MaxValue;
    numberVertices = 0; //初始化 numberVertices
}

void Graph::CreateVertices(int n)
{
    numberVertices = n;
}

void Graph::CreateEdge()
//根据一个图的边集生成其邻接表的算法
{
    char c1, c2, c3, c4;
    int i, j, weight;
    cout << "请输入如下格式的边信息：（顶点1，顶点2,权值），（顶点2，顶点3，权值）等，以#结束！" << endl;
    do
    {
        cin >> c1 >> i >> c2 >> j >> c2 >> weight >> c3;
        Edge[i][j] = weight; //置相应的对称元素为weight
        cin >> c4;
        if (c4 == '#')
            break;
    } while (1);
}

void Graph ::bfsMatrix(int i, bool *visited)
{   //从初始点vi出发广度优先搜索由邻接矩阵表示的图
    //定义队列的最大长度
    int q[MaxSize] = {0};
    //定义一个队列q，其元素类型应为整型
    int front = 0, rear = 0; //定义队首和队尾指针
    cout << i << ' ';        //访问初始点vi
    visited[i] = true;       //标记初始点vi已访问过
    q[++rear] = i;           //将已访问过的初始点序号i入队
    while (front != rear)
    {
        front = (front + 1) % MaxSize;
        int k = q[front];
        for (int j = 0; j < numberVertices; j++)
        { //依次搜索vk的每一个可能的邻接点
            if (Edge[k][j] != 0 && Edge[k][j] != MaxValue && !visited[j])
            {
                cout << j << ' ';  //访问一个未被访问过的邻接点vj
                visited[j] = true; //标记vj已访问过
                rear = (rear + 1) % MaxSize;
                q[rear] = j; //顶点序号j入队
            }
        }
    }
}

int main()
{
    Graph g;
    int m;
    cin >> m;
    g.CreateVertices(m);
    g.CreateEdge();
    g.bfsMatrix(0, &Visited[0]);
    cout << endl;
    return 0;
}
