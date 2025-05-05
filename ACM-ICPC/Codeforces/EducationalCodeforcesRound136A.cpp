/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound136A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-29
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
    vector<pair<int, int>> ans, direct(8);
    direct[0] = make_pair(1, 2);
    direct[1] = make_pair(1, -2);
    direct[2] = make_pair(-1, 2);
    direct[3] = make_pair(-1, -2);
    direct[4] = make_pair(2, 1);
    direct[5] = make_pair(2, -1);
    direct[6] = make_pair(-2, 1);
    direct[7] = make_pair(-2, -1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        bool flag = false;
        for (int k = 0; k < 8; k++) {
          if (i + direct[k].first >= 1 && i + direct[k].first <= n &&
              j + direct[k].second >= 1 && j + direct[k].second <= m) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          ans.push_back(make_pair(i, j));
        }
      }
    }
    if (ans.size() == 0) {
      cout << "1 1" << '\n';
    } else {
      cout << ans[0].first << " " << ans[0].second << '\n';
    }
  }

  return 0;
}
