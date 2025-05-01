/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#825C
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2022-10-11
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll ans = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
      while (r < n && a[r] >= r - l + 1) {
        r++;
      }
      ans += r - l;
    }
    cout << ans << '\n';
  }

  return 0;
}
