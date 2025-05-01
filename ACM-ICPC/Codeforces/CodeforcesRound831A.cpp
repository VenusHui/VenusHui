/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#831A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-29
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
    int n, ans = 0;
    cin >> n;
    if (n == 2) {
      ans = 2;
    } else {
      ans = 3;
    }
    cout << ans << '\n';
  }

  return 0;
}
