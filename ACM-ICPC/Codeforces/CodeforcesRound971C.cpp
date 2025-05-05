/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#971C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-03
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
    int x, y, k;
    cin >> x >> y >> k;
    int l, r;
    if (x % k)
      l = x / k + 1;
    else
      l = x / k;
    if (y % k)
      r = y / k + 1;
    else
      r = y / k;
    if (r >= l)
      cout << 2 * r << '\n';
    else
      cout << 2 * l - 1 << '\n';
  }

  return 0;
}
