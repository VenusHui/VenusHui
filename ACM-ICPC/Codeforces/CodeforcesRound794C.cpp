/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#794C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-26
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
    vector<int> a(n), fin(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      if (i * 2 < n) {
        fin[i * 2] = a[i];
      } else {
        if (n % 2 == 0) {
          fin[i * 2 - n + 1] = a[i];
        } else {
          fin[i * 2 - n] = a[i];
        }
      }
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (fin[i] > fin[i - 1 >= 0 ? i - 1 : n - 1] &&
              fin[i] > fin[i + 1 < n ? i + 1 : 0] ||
          fin[i] < fin[i - 1 >= 0 ? i - 1 : n - 1] &&
              fin[i] < fin[i + 1 < n ? i + 1 : 0]) {
        continue;
      } else {
        ans = false;
        break;
      }
    }
    if (ans) {
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++) {
        cout << fin[i] << " ";
      }
      cout << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
