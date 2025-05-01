/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#796B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-06
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
    int oddn = 0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      int num = a[i].first;
      if (num % 2 != 0) {
        oddn++;
        continue;
      }
      while (num % 2 == 0) {
        if (num == 0) {
          break;
        }
        a[i].second++;
        num /= 2;
      }
    }
    int minn = 1 << 30;
    for (int i = 0; i < n; i++) {
      minn = min(minn, a[i].second);
    }
    if (minn == 0) {
      cout << n - oddn << '\n';
    } else {
      cout << minn + n - 1 << '\n';
    }
  }

  return 0;
}
