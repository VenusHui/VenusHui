/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#832B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-04
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
    int n;
    cin >> n;
    int ans = n / 2 + n % 2;
    cout << ans << '\n';
    int l = 1, r = n;
    while (l < r) {
      cout << (l - 1) * 3 + 1 << " " << (r - 1) * 3 + 3 << '\n';
      l++;
      r--;
    }
    if (n % 2 != 0) {
      cout << n / 2 * 3 + 1 << " " << n / 2 * 3 + 3 << '\n';
    }
  }

  return 0;
}
