/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#835F
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-22
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    ll c;
    cin >> n >> c >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end(), [&](ll &a, ll &b) { return a > b; });
    ll ans = 0;
    for (int i = 0; i < min(n, d); i++) {
      ans += a[i];
    }
    if (ans >= c) {
      cout << "Infinity" << '\n';
      continue;
    }
    if (a[0] * d < c) {
      cout << "Impossible" << '\n';
      continue;
    }
    vector<ll> pre(n);
    partial_sum(a.begin(), a.end(), pre.begin());
    function<ll(int)> calc = [&](int day) {
      ll res = pre[min(day, n - 1)] * (d / (day + 1));
      if (d % (day + 1) != 0) {
        res += pre[min(d % (day + 1) - 1, n - 1)];
      }
      return res;
    };
    int x = 0;
    for (int i = 0; i < d; i++) {
      if (calc(i) >= c) {
        x = max(x, i);
      }
    }
    cout << x << '\n';
  }

  return 0;
}
