// this is a simple representation of bidirectional graph using STL
#include <iostream>
#include <vector>
using namespace std;

int vNum;
// 无向无权图
void addEdge(vector<int> graph[], int uNode, int vNode)
{
    graph[uNode].push_back(vNode);
    graph[vNode].push_back(uNode);
}

void printGraph(vector<int> graph[])
{
    for (int v = 0; v < vNum; ++v)
    {
        cout << "Adjacency list of vertex " << v;
        for (unsigned int i = 0; i < graph[v].size(); i++)
        {
            cout << " -> " << graph[v].at(i);
        }
        cout << endl;
    }
}

// 无向加权图，用边表示
typedef struct Edge{
    int _uNode;
    int _vNode;
    int _weight;
}*EdgeNode;

typedef vector<EdgeNode> WBGraph; // W：weighted 加权的    B：bidirectional 双向的

void addEdge(WBGraph wbGraph, int uNode, int vNode, int weight)
{
    EdgeNode temp = new Edge;
    temp->_uNode = uNode;
    temp->_vNode = vNode;
    temp->_weight = weight;
    wbGraph.push_back(temp);
}

// 无向加权图，用邻接链表表示
typedef struct ListNode{
    int dest;
    int weight;
    struct ListNode* next;
}*AdjList;

int main()
{
    cout << "Please input the vetrx num:";
    cin >> vNum;
    /*
    // 无向无权图
    vector<int> graph[vNum];
    int u, v;
    cout << endl << "Please input the node information:" << endl;
    for (int i = 0; i < vNum; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    printGraph(graph);
    */

    return 0;
}