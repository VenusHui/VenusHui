/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1076B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-25
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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];
    int l = -1, r = -1, cnt = -1;
    for (int i = 0; i < n; i++) {
      if (p[i] != n - i) {
        l = i;
        cnt = n - i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (p[i] == cnt) {
        r = i;
        break;
      }
    }
    vector<int> ans;
    for (int i = 0; i < l; i++) {
      ans.push_back(p[i]);
    }
    if (l != -1 && r != -1) {
      for (int i = r; i >= l; i--) {
        ans.push_back(p[i]);
      }
    }
    for (int i = r + 1; i < n; i++) {
      ans.push_back(p[i]);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
