/**
 * @platform: AcWing
 * @problem: P859
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-06
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.push_back({u - 1, v - 1, w});
  }
  function<int(vector<vector<int>> &, int)> kruskal =
      [&](vector<vector<int>> &g, int n) {
        vector<int> disjoint_set(n);
        for (int i = 0; i < n; i++)
          disjoint_set[i] = i;
        function<int(int)> find = [&](int x) {
          if (disjoint_set[x] != x)
            disjoint_set[x] = find(disjoint_set[x]);
          return disjoint_set[x];
        };
        function<void(int, int)> set_union = [&](int a, int b) {
          disjoint_set[find(a)] = find(b);
        };
        function<bool(int, int)> is_union = [&](int a, int b) {
          return find(a) == find(b);
        };

        sort(g.begin(), g.end(),
             [&](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });

        int ans = 0, edge_num = 0;
        for (auto &e : g) {
          if (!is_union(e[0], e[1])) {
            ans += e[2];
            set_union(e[0], e[1]);
            edge_num++;
          }
        }
        if (edge_num == n - 1)
          return ans;
        else
          return -1;
      };

  int ans = kruskal(g, n);
  if (ans == -1) {
    cout << "impossible" << '\n';
  } else {
    cout << ans << '\n';
  }

  return 0;
}
