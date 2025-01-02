/**
 * @platform: AcWing
 * @problem: P858 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-02
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    function<int(vector<vector<pair<int, int>>>&, int)> prim = [&] (vector<vector<pair<int, int>>>& g, int n) {
        vector<bool> s(n, false);
        vector<int> dist(n, 0x3f3f3f3f);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int t = -1;
            for (int j = 0; j < n; j++) {
                if (s[j] == false && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
            if (i) ans += dist[t];
            for (auto & e : g[t]) {
                dist[e.first] = min(dist[e.first], e.second);
            }
            s[t] = true;
        }

        return ans;
    };

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back(make_pair(v - 1, w));
        g[v - 1].push_back(make_pair(u - 1, w));
    }
    int ans = prim(g, n);

    if (ans == 0x3f3f3f3f) {
        cout << "impossible" << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}
