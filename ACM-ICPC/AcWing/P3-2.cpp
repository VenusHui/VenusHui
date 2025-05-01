/**
 * @platform: AcWing
 * @problem: P3-2
 * @version: Toturial Version
 * @author: VenusHui
 * @date: 2023-03-10
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> v(n), w(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> w[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= v[i - 1])
        dp[i][j] = max(dp[i][j], dp[i][j - v[i - 1]] + w[i - 1]);
    }
  }
  cout << dp[n][m] << '\n';

  return 0;
}