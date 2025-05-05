/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#827G
 * @version: Tutprial Version
 * @author: VenusHui
 * @date: 2022-10-23
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int maxn = 31;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), ans;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int tmp = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < min(maxn, n); i++) {
      int mx = 0, idx = -1;
      for (int j = 0; j < n; j++) {
        if (!vis[j] && (tmp | a[j]) > mx) {
          mx = (tmp | a[j]);
          idx = j;
        }
      }
      vis[idx] = true;
      ans.push_back(a[idx]);
      tmp |= a[idx];
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        ans.push_back(a[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }

  return 0;
}
