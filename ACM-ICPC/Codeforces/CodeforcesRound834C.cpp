/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#834C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-19
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
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    if (a == b) {
      cout << "0" << '\n';
      continue;
    }
    if (b - a >= x) {
      cout << "1" << '\n';
      continue;
    }
    if (b - l < x && r - b < x || a - l < x && r - a < x) {
      cout << "-1" << '\n';
      continue;
    }
    int ans = 1 << 30;
    if (b - l >= x) {
      if (a - l >= x) {
        ans = min(ans, 2);
      }
      if (r - a >= x) {
        ans = min(ans, 3);
      }
    }
    if (r - b >= x) {
      if (a - l >= x) {
        ans = min(ans, 3);
      }
      if (r - a >= x) {
        ans = min(ans, 2);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
