/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#971B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-03
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
    vector<string> mp(n);
    for (int i = 0; i < n; i++) {
      cin >> mp[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 4; j++) {
        if (mp[i][j] == '#') {
          cout << j + 1 << " ";
          break;
        }
      }
    }
    cout << '\n';
  }

  return 0;
}
