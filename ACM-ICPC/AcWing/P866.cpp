/**
 * @platform: AcWing
 * @problem: P866
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-18
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
    bool ans = n >= 2;
    for (int i = 2; i <= n / i; i++) {
      if (n % i == 0) {
        ans = false;
        break;
      }
    }
    if (ans)
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }

  return 0;
}
