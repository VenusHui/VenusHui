/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#795B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-31
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
    vector<int> s(n), ans(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    bool flag = true;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      if (i == n - 1 || s[i] != s[i + 1]) {
        if (i == tmp) {
          flag = false;
          break;
        }
        ans[tmp] = i + 1;
        for (int j = tmp + 1; j <= i; j++) {
          ans[j] = j;
        }
        tmp = i + 1;
      }
    }
    if (flag) {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
      }
      cout << '\n';
    } else {
      cout << "-1" << '\n';
    }
  }

  return 0;
}
