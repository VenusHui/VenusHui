/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#827A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-13
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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b + c || b == a + c || c == a + b) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
