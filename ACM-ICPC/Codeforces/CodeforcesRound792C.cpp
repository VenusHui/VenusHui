/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#792C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-19
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
    vector<vector<int>> res(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> res[i][j];
      }
    }
    pair<int, int> s = make_pair(m, m);
    for (int i = 1; i <= n; i++) {
      vector<int> tmp = res[i];
      sort(tmp.begin(), tmp.end());
      int flag = 0;
      bool ok = false;
      for (int j = 1; j <= m; j++) {
        if (tmp[j] != res[i][j]) {
          if (flag == 0) {
            ok = true;
            s.first = j;
            flag++;
          } else if (flag == 1) {
            s.second = j;
            flag++;
          }
        }
      }
      if (ok) {
        break;
      }
    }
    bool ans = true;
    for (int i = 1; i <= n; i++) {
      swap(res[i][s.first], res[i][s.second]);
      for (int j = 1; j < m; j++) {
        if (res[i][j] > res[i][j + 1]) {
          ans = false;
          break;
        }
      }
      if (!ans) {
        break;
      }
    }
    if (ans) {
      cout << s.first << " " << s.second << '\n';
    } else {
      cout << "-1" << '\n';
    }
  }

  return 0;
}
