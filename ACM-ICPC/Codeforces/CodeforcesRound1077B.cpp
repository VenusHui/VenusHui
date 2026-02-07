/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1077B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-02-05
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 1, ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        cnt++;
      if (s[i] == '1')
        cnt = 0;
      if (cnt == 3) {
        s[i] = '1';
        cnt = 0;
      }
    }
    if (cnt == 2)
      s[n - 1] = '1';
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
