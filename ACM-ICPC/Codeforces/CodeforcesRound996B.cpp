/**
 * @platform: Codeforces
 * @problem: CodeforcesRound996B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-12
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    int idx = -1, diff = 0;
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i]) {
        idx = i;
        diff = b[i] - a[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == idx)
        a[i] = b[i];
      else
        a[i] -= diff;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i]) {
        ans = false;
        break;
      }
    }
    if (ans) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
