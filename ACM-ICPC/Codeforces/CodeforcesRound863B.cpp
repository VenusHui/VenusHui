/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#863B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-04
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
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    auto check = [&](int x) {
      int ans = 0;
      if (x <= n / 2) {
        ans = n / 2 - x + 1;
      } else {
        ans = x - n / 2;
      }
      return ans;
    };
    auto calc = [&](int x, int y) { return max(check(x), check(y)); };
    cout << abs(calc(x1, y1) - calc(x2, y2)) << '\n';
  }

  return 0;
}
