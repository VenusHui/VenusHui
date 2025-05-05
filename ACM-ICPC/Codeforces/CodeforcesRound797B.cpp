/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#797B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-06-07
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
      num = max(num, a[i] - b[i]);
    }
    for (int i = 0; i < n; i++) {
      a[i] = max(a[i] - num, 0);
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
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
