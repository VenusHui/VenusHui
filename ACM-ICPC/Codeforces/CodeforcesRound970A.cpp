/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#970A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-01
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
    int a, b;
    cin >> a >> b;
    if (a < 2) {
      if (b % 2 == 0 && a != 1)
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
    } else {
      if (a % 2 == 0)
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
    }
  }

  return 0;
}
