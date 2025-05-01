/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#826E `
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-12
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
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
      if (i + b[i] <= n && dp[i - 1]) {
        dp[i + b[i]] = true;
      }
      if (i - b[i] - 1 >= 0 && dp[i - b[i] - 1]) {
        dp[i] = true;
      }
    }
    if (dp[n]) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
