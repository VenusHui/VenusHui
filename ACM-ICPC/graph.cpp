#include <iostream>
#include <algorithm>
using namespace std;
const int N = 4e5 + 5;
int n, m, etop;
struct Edge
{
    int u, v, w;
    struct Edge *next;
};
Edge epool[N];
struct Node
{
    Edge *first;
};
Node nodes[N];
void addedge(int u, int v, int w)
{
    epool[etop].u = u;
    epool[etop].v = v;
    epool[etop].w = w;
    epool[etop].next = nodes[u].first;
    nodes[u].first = &epool[etop];
    etop++;
}
int main()
{
    int u, v, w;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        addedge(u - 1, v - 1, w);
        addedge(v - 1, u - 1, w);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        Edge *e = nodes[i].first;
        int temp = e->w;
        while (e != nullptr)
        {
            if (temp > e->w)
            {
                temp = e->w;
            }
            e = e->next;
        }
        ans += temp;
    }
    cout << res << endl;
    
    return 0;
}