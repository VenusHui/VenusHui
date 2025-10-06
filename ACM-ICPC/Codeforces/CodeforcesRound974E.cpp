/**
 * @platform: Codeforces
 * @problem: CodeforcesRound974E 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-22
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

inline int dijsktra(vector<vector<pair<int, int>>> edge, int n, int s, int t) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> a(h);
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < h; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (find(a.begin(), a.end(), u) != a.end()) {
                g[u].push_back(make_pair(v, w / 2));
            }
            else {
                g[u].push_back(make_pair(v, w));
            }
            if (find(a.begin(), a.end(), v) != a.end()) {
                g[v].push_back(make_pair(u, w / 2));
            }
            else {
                g[v].push_back(make_pair(u, w));
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = i; i <= n; i++) {
            int a = dijsktra(g, n, 1, i);
            int b = dijsktra(g, n, i, n);
            if (a >= 0 && b >= 0) {
                ans = min(ans, a + b);
            }
        }
        if (ans == 0x3f3f3f3f) {
            cout << "-1" << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
