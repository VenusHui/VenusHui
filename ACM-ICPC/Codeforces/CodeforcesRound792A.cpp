/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#792A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-19
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
    int n, ans = 9;
    cin >> n;
    if (n < 100) {
      cout << n % 10 << '\n';
      continue;
    }
    while (n) {
      ans = min(ans, n % 10);
      n /= 10;
    }
    cout << ans << '\n';
  }

  return 0;
}
