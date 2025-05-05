/**
 * @platform: Codeforces
 * @problem: CodeforcesRound971D
 * @version: Contest Version
 * @author: VenusHui
 * @date:2024-09-04
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
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      p[i] = make_pair(x, y);
    }
    ll ans = 0;
    // 纵向直角边 + 其余任意一点
    unordered_map<int, int> xmp;
    for (int i = 0; i < n; i++)
      xmp[p[i].first]++;
    for (auto &e : xmp) {
      if (e.second == 2) {
        ans += n - 2;
      }
    }

    // 横向直角边
    unordered_map<int, bool> zymp, oymp;
    for (int i = 0; i < n; i++) {
      if (p[i].second == 0)
        zymp[p[i].first] = true;
      if (p[i].second == 1)
        oymp[p[i].first] = true;
    }
    for (auto &e : zymp) {
      if (zymp.find(e.first - 2) != zymp.end() &&
          oymp.find(e.first - 1) != oymp.end()) {
        ans++;
      }
    }
    for (auto &e : oymp) {
      if (oymp.find(e.first - 2) != oymp.end() &&
          zymp.find(e.first - 1) != zymp.end()) {
        ans++;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}