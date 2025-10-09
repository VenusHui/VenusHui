/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1027D
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-05-30
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
    vector<pair<int, int>> m(n);
    for (int i = 0; i < n; i++)
      cin >> m[i].first >> m[i].second;
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    vector<pair<int, int>> xm = m, ym = m;
    sort(xm.begin(), xm.end(), [&](pair<int, int> &a, pair<int, int> &b) {
      return a.first < b.first;
    });
    sort(ym.begin(), ym.end(), [&](pair<int, int> &a, pair<int, int> &b) {
      return a.second < b.second;
    });
    vector<pair<int, int>> tmp = {xm[0], xm[n - 1], ym[0], ym[n - 1]};
    ll ans = 1LL * 1e9 * 1e9;

    // xm[0]
    int ymin = 0x3f3f3f3f, ymax = -0x3f3f3f3f;
    for (int i = 1; i < n; i++) {
      ymax = max(xm[i].second, ymax);
      ymin = min(xm[i].second, ymin);
    }
    int xmin = xm[1].first, xmax = xm[n - 1].first;
    if (1LL * (xmax - xmin + 1) * (ymax - ymin + 1) > n - 1) {
      ans = min(ans, 1LL * (xmax - xmin + 1) * (ymax - ymin + 1));
    } else {
      if (ymax - ymin <= xmax - xmin) {
        ans = min(ans, 1LL * (xmax - xmin + 2) * (ymax - ymin + 1));
      } else {
        ans = min(ans, 1LL * (xmax - xmin + 1) * (ymax - ymin + 2));
      }
    }

    // xm[n - 1]
    ymin = 0x3f3f3f3f, ymax = -0x3f3f3f3f;
    for (int i = 0; i < n - 1; i++) {
      ymax = max(xm[i].second, ymax);
      ymin = min(xm[i].second, ymin);
    }
    xmin = xm[0].first, xmax = xm[n - 2].first;
    if (1LL * (xmax - xmin + 1) * (ymax - ymin + 1) > n - 1) {
      ans = min(ans, 1LL * (xmax - xmin + 1) * (ymax - ymin + 1));
    } else {
      if (ymax - ymin <= xmax - xmin) {
        ans = min(ans, 1LL * (xmax - xmin + 2) * (ymax - ymin + 1));
      } else {
        ans = min(ans, 1LL * (xmax - xmin + 1) * (ymax - ymin + 2));
      }
    }

    // ym[0]
    xmin = 0x3f3f3f3f, xmax = -0x3f3f3f3f;
    for (int i = 1; i < n; i++) {
      xmax = max(ym[i].first, xmax);
      xmin = min(ym[i].first, xmin);
    }
    ymin = ym[1].second, ymax = ym[n - 1].second;
    if (1LL * (xmax - xmin + 1) * (ymax - ymin + 1) > n - 1) {
      ans = min(ans, 1LL * (xmax - xmin + 1) * (ymax - ymin + 1));
    } else {
      if (ymax - ymin <= xmax - xmin) {
        ans = min(ans, 1LL * (xmax - xmin + 2) * (ymax - ymin + 1));
      } else {
        ans = min(ans, 1LL * (xmax - xmin + 1) * (ymax - ymin + 2));
      }
    }

    // y[n - 1]
    xmin = 0x3f3f3f3f, xmax = -0x3f3f3f3f;
    for (int i = 0; i < n - 1; i++) {
      xmax = max(ym[i].first, xmax);
      xmin = min(ym[i].first, xmin);
    }
    ymin = ym[0].second, ymax = ym[n - 2].second;
    if (1LL * (xmax - xmin + 1) * (ymax - ymin + 1) > n - 1) {
      ans = min(ans, 1LL * (xmax - xmin + 1) * (ymax - ymin + 1));
    } else {
      if (ymax - ymin <= xmax - xmin) {
        ans = min(ans, 1LL * (xmax - xmin + 2) * (ymax - ymin + 1));
      } else {
        ans = min(ans, 1LL * (xmax - xmin + 1) * (ymax - ymin + 2));
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
