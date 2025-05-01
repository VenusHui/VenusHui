/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#821A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-19
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> res(k);
    for (int i = 0; i < n; i++) {
      res[i % k].push_back(a[i]);
    }
    for (int i = 0; i < k; i++) {
      sort(res[i].begin(), res[i].end(), [&](int &a, int &b) { return a > b; });
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
      ans += res[i][0];
    }
    cout << ans << '\n';
  }

  return 0;
}
