/**
 * @platform: Codeforces
 * @problem: PinelyRound#1A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-20
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
    int n, a, b;
    cin >> n >> a >> b;
    if (n == a && n == b) {
      cout << "Yes" << '\n';
      continue;
    }
    if (n < a + b + 2) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
    }
  }

  return 0;
}
