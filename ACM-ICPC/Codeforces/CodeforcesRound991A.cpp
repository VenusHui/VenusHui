/**
 * @platform: Codeforces
 * @problem: CodeforcesRound991A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-12-05
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int size = s[i].size();
      if ((m - size) < 0)
        break;
      if ((m - size) >= 0) {
        ans += 1;
        m -= size;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
