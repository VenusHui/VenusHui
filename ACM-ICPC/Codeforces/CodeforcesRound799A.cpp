/**
 * @platform: Codeforces
 * @problem: CodeforcesRound$799A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-13
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if (b > a) {
      ans++;
    }
    if (c > a) {
      ans++;
    }
    if (d > a) {
      ans++;
    }
    cout << ans << '\n';
  }

  return 0;
}
