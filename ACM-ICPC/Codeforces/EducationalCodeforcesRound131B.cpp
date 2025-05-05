/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound131B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-08
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
    int n, d = 2;
    cin >> n;
    vector<int> ans(n);
    set<int> res;
    for (int i = 1; i <= n; i++) {
      res.insert(i);
    }
    int tmp = 1;
    for (int i = 0; i < n; i++) {
      if (tmp <= n && res.find(tmp) != res.end()) {
        ans[i] = tmp;
        res.erase(tmp);
        tmp *= 2;
      } else {
        tmp = *res.begin();
        i--;
      }
    }
    cout << d << '\n';
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
