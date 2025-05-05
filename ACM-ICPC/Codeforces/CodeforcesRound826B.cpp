/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#826B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-11
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
    if (n == 3) {
      cout << "-1" << '\n';
      continue;
    }
    vector<int> a(n), res(n);
    for (int i = 0; i < n; i++) {
      a[i] = i + 1;
    }
    if (n % 2 == 0) {
      for (int i = 0; i < n; i += 2) {
        res[i] = a[i + 1];
        res[i + 1] = a[i];
      }
    } else {
      for (int i = 0; i < n; i += 2) {
        if (i == n - 3) {
          res[i] = a[0];
          res[i + 1] = a[1];
          res[i + 2] = a[2];
          break;
        }
        res[i] = a[n - 1 - i - 1];
        res[i + 1] = a[n - 1 - i];
      }
    }

    for (int i = 0; i < n; i++) {
      cout << res[i] << " ";
    }
    cout << '\n';
  }

  return 0;
}
