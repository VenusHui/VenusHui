/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#836C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-26
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
    int n, x;
    cin >> n >> x;
    map<int, bool> mp;
    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
        mp[i] = true;
      }
    }
    if (mp[x]) {
      vector<int> p(n + 1, -1);
      p[1] = x, p[n] = 1;
      if (p[x] == -1) {
        p[x] = n;
      }
      for (int i = 1; i <= n; i++) {
        if (p[i] == -1) {
          p[i] = i;
        }
      }
      int idx = x;
      while (idx <= n) {
        bool flag = false;
        for (int i = idx + 1; i <= n; i++) {
          if (p[i] % idx == 0 && p[idx] % i == 0) {
            swap(p[idx], p[i]);
            flag = true;
            idx = i;
            break;
          }
        }
        if (!flag) {
          break;
        }
      }
      for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
      }
      cout << '\n';
    } else {
      cout << "-1" << '\n';
    }
  }

  return 0;
}
