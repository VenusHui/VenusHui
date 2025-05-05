/**
 * @platform: Codeforces
 * @problem: CodeforcesRound974D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-21
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> start(k), end(k);
    for (int i = 0; i < k; i++) {
      cin >> start[i] >> end[i];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int sp = 0, ep = 0;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      dp[i] += dp[i - 1];
      while (sp < k && start[sp] == i) {
        dp[start[sp]]++;
        sp++;
      }
      while (ep < k && end[ep] == i) {
        if (end[ep] + d <= n) {
          dp[end[ep] + d]--;
        }
        ep++;
      }
    }
    pair<int, int> mmax = make_pair(-1, -1);
    pair<int, int> mmin = make_pair(-1, 0x3f3f3f3f);
    for (int i = 1; i <= n; i++) {
      if (dp[i] > mmax.second && i - d + 1 >= 1) {
        mmax = make_pair(i, dp[i]);
      }
      if (dp[i] < mmin.second && i - d + 1 >= 1) {
        mmin = make_pair(i, dp[i]);
      }
    }
    cout << mmax.first - d + 1 << " " << mmin.first - d + 1 << '\n';
  }

  return 0;
}
