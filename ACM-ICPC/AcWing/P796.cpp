/**
 * @platform: AcWing
 * @problem: P796
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
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] +
                  matrix[i - 1][j - 1];
    }
  }
  while (q--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] +
                pre[x1 - 1][y1 - 1]
         << '\n';
  }

  return 0;
}
