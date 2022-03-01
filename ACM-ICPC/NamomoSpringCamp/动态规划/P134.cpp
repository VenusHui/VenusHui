// 最短路问题
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
typedef long long ll;
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int graph[1001][1001], dp[1001];
    memset(graph, 127, sizeof(graph));
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w);
    }
    memset(dp, 127, sizeof(dp));
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (graph[j][i] < 1 << 30 && dp[j] < 1 << 30)
            {
                dp[i] = min(dp[i], dp[j] + graph[j][i]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}