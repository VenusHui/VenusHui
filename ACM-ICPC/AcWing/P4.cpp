/**
 * @platform: AcWing
 * @problem: P4-1
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
  vector<int> v(n), w(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> w[i] >> s[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= s[i - 1] && k * v[i - 1] <= j; k++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i - 1]] + k * w[i - 1]);
      }
    }
  }
  cout << dp[n][m] << '\n';

  return 0;
}
