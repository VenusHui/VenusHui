/**
 * @platform: Codeforces
 * @problem: CodeforcesGlobalRound23B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-15
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
    vector<int> zeo, one;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
      for (l; l < n && l < r; l++) {
        if (a[l] == 1) {
          break;
        }
      }
      for (r; r >= 0 && l < r; r--) {
        if (a[r] == 0) {
          break;
        }
      }
      if (l < r) {
        a[l] = 0;
        a[r] = 1;
        ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
