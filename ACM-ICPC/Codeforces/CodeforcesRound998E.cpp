/**
 * @platform: Codeforces
 * @problem: CodeforcesRound998E
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class DSU {
private:
  vector<int> disjoint_set;

public:
  DSU(int n) {
    for (int i = 0; i < n; i++) {
      disjoint_set.push_back(i);
    }
  }

  int find(int x) {
    if (disjoint_set[x] != x)
      disjoint_set[x] = find(disjoint_set[x]);
    return disjoint_set[x];
  }

  void set_union(int a, int b) { disjoint_set[find(a)] = find(b); }

  bool is_union(int a, int b) { return find(a) == find(b); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU f(n), g(n);
    vector<vector<int>> fv(n), gv(n);
    for (int i = 0; i < m1; i++) {
      int u, v;
      cin >> u >> v;
      fv[u - 1].push_back(v - 1);
    }
    for (int i = 0; i < m2; i++) {
      int u, v;
      cin >> u >> v;
      gv[u - 1].push_back(v - 1);
      g.set_union(u - 1, v - 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (auto &j : fv[i]) {
        if (!g.is_union(i, j)) {
          ans++;
        } else {
          f.set_union(i, j);
        }
      }
    }
    set<int> fs, gs;
    for (int i = 0; i < n; i++) {
      fs.insert(f.find(i));
      gs.insert(g.find(i));
    }
    ans = ans + fs.size() - gs.size();
    cout << ans << '\n';
  }

  return 0;
}
