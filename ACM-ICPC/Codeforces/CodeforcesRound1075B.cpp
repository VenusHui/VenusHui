/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1075B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-23
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    ll x;
    cin >> n >> x;
    lll total_free = 0;
    lll G = -(lll)1e36;

    for (int i = 0; i < n; i++) {
      ll a, b, c;
      cin >> a >> b >> c;
      if (total_free < x) {
        lll free_i = (lll)(b - 1) * a;
        if (free_i >= (lll)x - total_free) {
          total_free = x;
        } else {
          total_free += free_i;
        }
      }
      lll g_i = (lll)b * a - c;
      G = max(G, g_i);
    }
    if (total_free >= x) {
      cout << 0 << '\n';
      continue;
    }
    if (G <= 0) {
      cout << -1 << '\n';
      continue;
    }
    lll need = (lll)x - total_free;
    lll ans = (need + G - 1) / G;

    cout << (ll)ans << '\n';
  }
  return 0;
}
