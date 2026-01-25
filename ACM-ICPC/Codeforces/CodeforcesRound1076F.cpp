/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1076F
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-25
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
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
      cin >> x[i];
    for (int i = 0; i < n; i++)
      cin >> y[i];
    map<ll, pair<ll, ll>> mp;
    for (int i = 0; i < n; i++) {
      if (mp.find(x[i]) == mp.end()) {
        mp[x[i]] = make_pair(y[i], y[i]);
      } else {
        mp[x[i]].first = min(mp[x[i]].first, y[i]);
        mp[x[i]].second = max(mp[x[i]].second, y[i]);
      }
    }
    vector<vector<ll>> g;
    for (auto &e : mp) {
      g.push_back({e.first, e.second.first, e.second.second});
    }
    int m = g.size();
    ll dp0, dp1;
    ll dx = g[0][0] - ax;
    ll range0 = g[0][2] - g[0][1];
    dp1 = dx + abs(ay - g[0][1]) + range0;
    dp0 = dx + abs(ay - g[0][2]) + range0;
    for (int i = 1; i < m; i++) {
      ll dxi = g[i][0] - g[i - 1][0];
      ll range = g[i][2] - g[i][1];
      ll ndp0 = LLONG_MAX, ndp1 = LLONG_MAX;
      ndp1 = min(ndp1, dp0 + dxi + abs(g[i - 1][1] - g[i][1]) + range);
      ndp0 = min(ndp0, dp0 + dxi + abs(g[i - 1][1] - g[i][2]) + range);
      ndp1 = min(ndp1, dp1 + dxi + abs(g[i - 1][2] - g[i][1]) + range);
      ndp0 = min(ndp0, dp1 + dxi + abs(g[i - 1][2] - g[i][2]) + range);
      dp0 = ndp0;
      dp1 = ndp1;
    }
    ll tmp = bx - g[m - 1][0];
    ll ans = min(dp0 + tmp + abs(g[m - 1][1] - by),
                 dp1 + tmp + abs(g[m - 1][2] - by));
    cout << ans << '\n';
  }
  return 0;
}
