/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1023A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-05-05
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
  function<int(int, int)> gcd = [&](int a, int b) {
    while (b != 0) {
      int tmp = b;
      b = a % b;
      a = tmp;
    }
    return a;
  };
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxn = -0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (maxn < a[i])
        maxn = a[i];
    }
    vector<int> b, c;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (a[i] == maxn) {
        ans[i] = 2;
        c.push_back(a[i]);
      } else {
        ans[i] = 1;
        b.push_back(a[i]);
      }
    }
    if (b.size() == n || c.size() == n) {
      cout << "NO" << '\n';
      continue;
    }
    int tmp = b[0];
    for (auto &e : b) {
      tmp = gcd(e, tmp);
    }
    if (tmp == maxn) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }

  return 0;
}
