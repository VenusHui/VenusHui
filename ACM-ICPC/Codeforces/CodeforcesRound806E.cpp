/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#806E
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-12
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
    int n, ans = 0;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
      cin >> grid[i];
    }
    if (n % 2 == 0) {

    } else {
    }
    for (int i = 0; i < (n + 1) / 2; i++) {
      for (int j = 0; j < (n + 1) / 2; j++) {
        pair<int, int> a, b, c, d;
        a = make_pair(i, j);
        b = make_pair(j, n - 1 - i);
        c = make_pair(n - 1 - i, n - 1 - j);
        d = make_pair(n - 1 - j, i);
        int tmp = grid[a.first][a.second] + grid[b.first][b.second] +
                  grid[c.first][c.second] + grid[d.first][d.second] - 4 * '0';
        if (tmp == 0 || tmp == 4) {
          ans += 0;
        } else if (tmp == 1 || tmp == 3) {
          ans += 1;
        } else if (tmp == 2) {
          ans += 2;
        }
        grid[a.first][a.second] = grid[b.first][b.second] =
            grid[c.first][c.second] = grid[d.first][d.second] = '1';
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
