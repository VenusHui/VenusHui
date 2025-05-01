/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#829A
 * @version: Contest Version
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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'Q') {
        tmp++;
      } else {
        tmp = max(0, tmp - 1);
      }
    }
    if (tmp <= 0) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

  return 0;
}
