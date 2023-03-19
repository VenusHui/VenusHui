/**
 * @platform: Nowcoder_Baidu
 * @problem: baidu_testC 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-13
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.insert(s.begin(), '$');
    vector<pair<int, int>> edge(n);
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edge[i] = make_pair(u, v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = edge[i].first, v = edge[i].second;
        queue<int> uq, vq;
        uq.push(u), vq.push(v);
        vector<bool> vis(n + 1, false);
        function<int(queue<int>&)> dbfs = [&] (queue<int>& q) {
            int ans = 0;
            while (!q.empty()) {
                int cnt = q.front();
                q.pop();
                for (auto& e : tree[cnt]) {
                    if (cnt == u && e == v || cnt == v && e == u) continue;
                    char color = s[cnt];
                    function<void(int)> dfs = [&] (int x) {
                        if (s[x] != color || vis[x]) return;
                        vis[x] = true;
                        for (auto& ed : tree[x]) {
                            if (x == u && ed == v || x == v && ed == u) continue;
                            if (s[ed] == color) dfs(ed);
                            else {
                                q.push(ed);
                            }
                        }
                    };
                    dfs(cnt);
                }
                ans++;
            }
            return ans;
        };
        int aa = dbfs(uq), bb = dbfs(vq);
        res += abs(aa - bb);
    }
    cout << res << '\n';

    return 0;
}
