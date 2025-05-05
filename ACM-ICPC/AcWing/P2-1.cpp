/**
 * @platform: AcWing
 * @problem: P2-1
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
  int n, maxv;
  cin >> n >> maxv;
  vector<int> v(n), w(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> w[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(maxv + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= maxv; j++) {
      if (j < v[i - 1])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
    }
  }
  cout << dp[n][maxv] << '\n';

  return 0;
}
