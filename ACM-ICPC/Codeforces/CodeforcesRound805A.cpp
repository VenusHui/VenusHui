/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#805A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-10
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
  vector<ll> res = {1LL,         10LL,         100LL,        1000LL,
                    10000LL,     100000LL,     1000000LL,    10000000LL,
                    100000000LL, 1000000000LL, 10000000000LL};
  int size = res.size();
  while (t--) {
    ll m, ans = 0;
    cin >> m;
    for (int i = 0; i < size; i++) {
      if (m >= res[i]) {
        ans = m - res[i];
      } else {
        cout << ans << '\n';
        break;
      }
    }
  }

  return 0;
}
