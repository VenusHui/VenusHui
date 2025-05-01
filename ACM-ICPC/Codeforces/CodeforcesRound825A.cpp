/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#825A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-10
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
    int anum = 0, bnum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        anum++;
      }
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (b[i] == 1) {
        bnum++;
      }
    }
    bool flag = true;
    int maxn = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        maxn++;
        flag = false;
      }
    }
    if (flag) {
      cout << "0" << '\n';
    } else {
      int ans = min(maxn, abs(anum - bnum) + 1);
      cout << ans << '\n';
    }
  }

  return 0;
}
