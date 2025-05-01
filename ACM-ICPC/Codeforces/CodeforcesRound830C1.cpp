/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#830C1
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-27
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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), presum(n + 1), prexor(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    presum[0] = prexor[0] = 0LL;
    for (int i = 1; i <= n; i++) {
      presum[i] = presum[i - 1] + a[i - 1];
      prexor[i] = prexor[i - 1] ^ a[i - 1];
    }
    function<ll(int, int)> calc = [&](int l, int r) {
      return presum[r] - presum[l - 1] - (prexor[r] ^ prexor[l - 1]);
    };
    while (q--) {
      int l, r;
      cin >> l >> r;
      ll ans = calc(1, 1);
      pair<int, int> pos = make_pair(1, 1);
      for (int i = l; i <= r; i++) {
        ll a = i, b = r, tmp = calc(i, r);
        while (a < b) {
          ll mid = (a + b) >> 1;
          if (calc(i, mid) < tmp) {
            a = mid + 1;
          } else {
            b = mid;
          }
        }
        if (calc(i, a) > ans) {
          pos = make_pair(i, a);
          ans = calc(i, a);
        } else if (calc(i, a) == ans && pos.second - pos.first > a - i) {
          pos = make_pair(i, a);
        }
      }
      cout << pos.first << " " << pos.second << '\n';
    }
  }

  return 0;
}
