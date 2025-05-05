/**
 * @platform: Codeforces
 * @problem: CodeforcesRound991D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-12-05
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
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
      if (s[i + 1] - s[i] > 1) {
        s[i + 1]--;
        swap(s[i], s[i + 1]);
        i -= 2;
      }
      if (i < -1)
        i = -1;
    }
    cout << s << '\n';
  }

  return 0;
}
