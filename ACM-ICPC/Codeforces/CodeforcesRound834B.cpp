/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#834B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int maxn = 1000;
  int t;
  cin >> t;
  while (t--) {
    int m, s;
    cin >> m >> s;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    int maxpos = 0;
    vector<bool> mp(maxn, false);
    for (int i = 0; i < m; i++) {
      mp[b[i]] = true;
      maxpos = max(maxpos, b[i]);
    }
    bool flag = false;
    for (int i = 0; i < maxn; i++) {
      if (!mp[i]) {
        mp[i] = true;
        s -= i;
      }
      if (s == 0) {
        flag = true;
      }
      if (s <= 0) {
        break;
      }
    }
    for (int i = 1; i <= maxpos; i++) {
      if (!mp[i]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

  return 0;
}
