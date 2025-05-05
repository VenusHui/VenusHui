/**
 * @platform: Codeforces
 * @problem: CodeforcesRound970E
 * @version: Contest Version
 * @author: VenusHui
 * @date:2024-09-04
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
    ll n, k;
    cin >> n >> k;
    auto pre = [&](ll x) { return 1LL * (k + k + x - 1) * x / 2; };
    // 结果不小于 0 的最小 l
    ll l = 0, r = n;
    while (l < r) {
      ll m = (l + r) / 2;
      if (pre(m) - (pre(n) - pre(m)) >= 0) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    ll tmp = l;
    // 结果不大于 0 的最大 l
    l = 0, r = n;
    while (l < r) {
      ll m = (l + r + 1) / 2;
      if (pre(m) - (pre(n) - pre(m)) <= 0) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    auto calc = [&](ll x) { return abs(pre(x) - (pre(n) - pre(x))); };
    cout << min(calc(tmp), calc(l)) << '\n';
  }

  return 0;
}