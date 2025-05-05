/**
 * @platform: Codeforeces
 * @problem: CodeforcesRound#817D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-13
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
    string s;
    cin >> s;
    ll ans = 0;
    vector<int> res(n), tmp(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        res[i] = i;
      } else {
        res[i] = n - 1 - i;
      }
      ans += res[i];
      tmp[i] = max(i, n - 1 - i) - res[i];
    }
    sort(tmp.begin(), tmp.end(), [&](int &a, int &b) { return a > b; });
    for (int i = 0; i < n; i++) {
      ans += tmp[i];
      cout << ans << " ";
    }
    cout << '\n';
  }

  return 0;
}
