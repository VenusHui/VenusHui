/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1076D
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + b[i];
    }
    function<ll(int)> calc = [&](int cnt) { return pre[cnt]; };
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int cnt = n - i;
      int l = 0, r = n;
      while (l < r) {
        int m = (l + r + 1) >> 1;
        if (calc(m) > cnt) {
          r = m - 1;
        } else {
          l = m;
        }
      }
      ans = max(ans, 1LL * a[i] * l);
    }
    cout << ans << '\n';
  }
  return 0;
}
