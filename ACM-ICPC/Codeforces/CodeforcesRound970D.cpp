/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#970D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-01
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];
    string s;
    cin >> s;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[i] = p[i] - 1;
    }
    vector<vector<int>> ans(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
      function<void(int, int)> dfs = [&](int idx, int cnt) {
        if (vis[cnt])
          return;
        vis[cnt] = true;
        dfs(idx, mp[cnt]);
        ans[idx].push_back(cnt);
      };
      dfs(i, i);
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      int num = 0;
      for (auto &e : ans[i]) {
        if (s[e] == '0') {
          num++;
        }
      }
      for (auto &e : ans[i]) {
        res[e] = max(res[e], num);
      }
    }
    for (int i = 0; i < n; i++)
      cout << res[i] << " ";
    cout << '\n';
  }

  return 0;
}
