/**
 * @platform: Codeforces
 * @problem: CodeforcesRound999A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-20
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int onum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2)
        onum++;
    }
    if (onum < n) {
      cout << onum + 1 << '\n';
    } else if (onum == n) {
      cout << n - 1 << '\n';
    }
  }

  return 0;
}
