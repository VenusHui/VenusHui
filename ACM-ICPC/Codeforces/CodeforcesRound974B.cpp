/**
 * @platform: Codeforces
 * @problem: CodeforcesRound974B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-21
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
    int n, k;
    cin >> n >> k;
    int total = n - max(1, n - k + 1) + 1;
    int ans = total / 2;
    if (max(1, n - k + 1) % 2 && total % 2) {
      ans++;
    }
    if (ans % 2 == 0) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

  return 0;
}
