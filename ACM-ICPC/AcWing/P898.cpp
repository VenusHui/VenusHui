/**
 * @platform: AcWing
 * @problem: P898
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> tri(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int x;
      cin >> x;
      tri[i].push_back(x);
    }
  }
  vector<int> dp(n, -0x3f3f3f3f);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      if (j - 1 >= 0)
        dp[j] = max(dp[j], dp[j - 1]) + tri[i][j];
      else
        dp[j] += tri[i][j];
    }
  }
  int ans = -0x3f3f3f3f;
  for (auto &e : dp)
    ans = max(ans, e);
  cout << ans << '\n';

  return 0;
}
