#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <numeric>
#include <iomanip>
typedef long long ll;
using namespace std;

// 最短路：Dijkstra堆优化

int n, m, k;

inline int dijsktra(vector<vector<pair<int, int>>> edge, int s, int t) {
    vector<int> dist(n + 1, (1 << 30) + 1);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(dist[s], s));
    while (!q.empty()) {
        int x = q.top().second;
        if (x == t || dist[x] > 1 << 30) {
            break;
        }
        q.pop();
        for (auto it : edge[x]) {
            if (dist[x] + it.second < dist[it.first]) {
                dist[it.first] = dist[x] + it.second;
                q.push(make_pair(dist[it.first], it.first));
            }
        }
    }
    if (dist[t] > 1 << 30) {
        return -1;
    }
    return dist[t];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> edge(n + 1);
    for (int i = 0; i < m; i++) {
        int s, t, v;
        cin >> s >> t >> v;
        edge[s].push_back(make_pair(t, v));
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        cout << dijsktra(edge, x, y) << '\n';
    }
    
    return 0;
}

