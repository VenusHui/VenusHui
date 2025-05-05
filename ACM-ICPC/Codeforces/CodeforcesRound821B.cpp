/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#821B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-19
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
    int n, x, y;
    cin >> n >> x >> y;
    int m = max(x, y), l = min(x, y);
    if (l != 0 || l + m == 0) {
      cout << "-1" << '\n';
      continue;
    }
    if ((n - 1) % m != 0) {
      cout << "-1" << '\n';
      continue;
    }
    int num = 0, p = 1;
    for (int i = 0; i < n - 1; i++) {
      num++;
      cout << p << " ";
      if (num % m == 0) {
        if (p == 1) {
          p += (m + 1);
        } else {
          p += m;
        }
        num = 0;
      }
    }
    cout << '\n';
  }

  return 0;
}
