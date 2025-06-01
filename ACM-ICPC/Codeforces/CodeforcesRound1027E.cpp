/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1027E
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-05-30
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
      cin >> a[i];
    vector<vector<ll>> tree(n);
    for (ll i = 0; i < n - 1; i++) {
      ll u, v;
      cin >> u >> v;
      tree[u - 1].push_back(v - 1);
      tree[v - 1].push_back(u - 1);
    }
    vector<ll> dp1(n, 0), dp2(n, 0);
    dp1[0] = dp2[0] = a[0];
    function<void(ll, ll)> dfs = [&](ll cnt, ll p) {
      for (auto &e : tree[cnt]) {
        if (e == p)
          continue;
        dp1[e] = max(a[e], a[e] - dp2[cnt]);
        dp2[e] = min(a[e], a[e] - dp1[cnt]);
        dfs(e, cnt);
      }
    };
    dfs(0, -1);
    for (ll i = 0; i < n; i++) {
      cout << dp1[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
