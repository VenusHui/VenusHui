/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#793A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-22
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
    int n, ans = 1;
    cin >> n;
    string s;
    cin >> s;
    int mid = n / 2;
    for (int i = mid; i < n; i++) {
      if (i + 1 < n && s[i] == s[i + 1]) {
        ans++;
      } else {
        break;
      }
    }
    for (int i = mid; i >= 0; i--) {
      if (i - 1 >= 0 && s[i] == s[i - 1]) {
        ans++;
      } else {
        break;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
