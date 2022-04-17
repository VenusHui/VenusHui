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
#include <iomanip>
typedef long long ll;
using namespace std;

// 最短路：Bellman-Ford
int n, m, k;

int bellman(vector<vector<int>>& edge, int s, int e) {
    bool flag = true;
    vector<int> dist(n + 1, 1 << 30);
    dist[s] = 0;
    while (flag) {
        flag = false;
        for (int i = 0; i < m; i++) {
            int tmp = dist[edge[i][1]];
            dist[edge[i][1]] = min(dist[edge[i][1]], dist[edge[i][0]] + edge[i][2]);
            if (dist[edge[i][1]] != tmp) {
                flag = true;
            }
        }
    }
    if (dist[e] < 1 << 30) {
        return dist[e];
    }
    else {
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    vector<vector<int> > edge(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        cout << bellman(edge, x, y) << '\n';
    }

    return 0;
}
