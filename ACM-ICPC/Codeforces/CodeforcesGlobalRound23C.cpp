/**
 * @platform: Codeforces
 * @problem: CodeforcesGlobalRound23C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-15
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
    vector<int> a(n);
    vector<pair<int, int>> ans(n, make_pair(0, 1));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i && a[i - 1] > a[i]) {
        ans[i].first = a[i - 1] - a[i] + 1;
        ans[i].second = max(i + 1, ans[i].second);
      }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
      cout << ans[i].second << ' ';
    }
    cout << '\n';
  }

  return 0;
}
