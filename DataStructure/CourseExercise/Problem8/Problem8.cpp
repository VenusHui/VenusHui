// 电网造价模拟系统
#include <iostream>
#include <string>
using namespace std;

class GraphForSol
{
private:
    int vNum, ** adjMatrix;
    int* parent, * key;
    bool* mstSet;
    string* nameRes, start;

public:
    GraphForSol();
    ~GraphForSol();
    void addVertex();
    int findIndex(string& name);
    void addEdge();
    int minKey();
    void primMST();
    void printMST();
};

GraphForSol::GraphForSol()
{
    vNum = 0;
    adjMatrix = nullptr;
    parent = key = nullptr;
    mstSet = nullptr;
    nameRes = nullptr;
    start = "";
    cout << "**           电网造价模拟系统          **" << endl;
    cout << "=========================================" << endl;
    cout << "**          A --- 创建电网顶点         **" << endl;
    cout << "**          B --- 添加电网的边         **" << endl;
    cout << "**          C --- 构造最小生成树       **" << endl;
    cout << "**          D --- 显示最小生成树       **" << endl;
    cout << "**          E --- 退出程序             **" << endl;
    cout << "=========================================" << endl;
}

GraphForSol::~GraphForSol()
{
}

void GraphForSol::addVertex()
{
    cout << "请输入顶点个数：" << endl;
    cin >> vNum;
    nameRes = new string[vNum];
    cout << "请输入各顶点名称：" << endl;
    for (int i = 0; i < vNum; i++)
    {
        cin >> nameRes[i];
    }
}

int GraphForSol::findIndex(string& name)
{
    for (int i = 0; i < vNum; i++)
    {
        if (name == nameRes[i])
        {
            return i;
        }
    }
    return -1;
}

void GraphForSol::addEdge()
{
    adjMatrix = new int* [vNum];
    for (int i = 0; i < vNum; i++)
    {
        adjMatrix[i] = new int[vNum];
    }
    for (int i = 0; i < vNum * (vNum - 1) / 2; i++)
    {
        // 确保是完全图
        string start, end;
        int weight, sIndex, eIndex;
        cout << endl
            << "请输入两个顶点及边：";
        cin >> start >> end >> weight;
        sIndex = findIndex(start);
        eIndex = findIndex(end);
        adjMatrix[sIndex][eIndex] = weight;
        adjMatrix[eIndex][sIndex] = weight;
    }
}

int GraphForSol::minKey()
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < vNum; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void GraphForSol::primMST()
{
    cout << "请输入起始顶点：";
    cin >> start;
    cout << "生成Prim最小生成树！" << endl;
    parent = new int[vNum];
    key = new int[vNum];
    mstSet = new bool[vNum];
    for (int i = 0; i < vNum; i++)
    {
        key[i] = INT_MAX, mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < vNum - 1; count++)
    {
        int u = minKey();
        mstSet[u] = true;
        for (int v = 0; v < vNum; v++)
        {
            if (adjMatrix[u][v] && mstSet[v] == false && adjMatrix[u][v] < key[v])
            {
                parent[v] = u, key[v] = adjMatrix[u][v];
            }
        }
    }
}

void GraphForSol::printMST()
{
    int count = 1;
    int sIndex = findIndex(start) + 1;
    cout << "最小生成树的顶点及边为：" << endl;
    for (int i = sIndex; i <= vNum && count < vNum; i++, count++)
    {
        if (i == vNum)
        {
            i = 1;
        }
        cout << nameRes[parent[i]] << "-(" << adjMatrix[i][parent[i]] << ")->" << nameRes[i] << endl;
    }
}

int main()
{
    char oper;
    int loop = 1;
    GraphForSol graph;
    while (loop)
    {
        cout << "请选择操作：";
        cin >> oper;
        switch (oper)
        {
            case 'A':
                graph.addVertex();
                break;
            case 'B':
                graph.addEdge();
                break;
            case 'C':
                graph.primMST();
                break;
            case 'D':
                graph.printMST();
                break;
            case 'E':
                loop = 0;
            default:
                break;
        }
    }

    return 0;
}