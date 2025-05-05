/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#806A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-12
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
    string s;
    cin >> s;
    for (auto &it : s) {
      if (it >= 'a' && it <= 'z') {
        it += 'A' - 'a';
      }
    }
    if (s == "YES") {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
