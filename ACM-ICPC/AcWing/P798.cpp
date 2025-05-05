/**
 * @platform: AcWing
 * @problem: P798
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-11
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  vector<vector<int>> pre(n + 1, vector<int>(m + 1));
  function<void(int, int, int, int, int)> insert = [&](int x1, int y1, int x2,
                                                       int y2, int c) {
    pre[x1][y1] += c, pre[x2 + 1][y1] -= c, pre[x1][y2 + 1] -= c,
        pre[x2 + 1][y2 + 1] += c;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      insert(i, j, i, j, matrix[i][j]);
    }
  }
  while (q--) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    insert(x1 - 1, y1 - 1, x2 - 1, y2 - 1, c);
  }
  vector<vector<int>> ans(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans[i][j] =
          ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + pre[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}
