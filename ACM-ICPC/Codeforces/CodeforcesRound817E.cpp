/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#817E
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-13
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
    int n, q;
    cin >> n >> q;
    vector<int> areas(n);
    vector<vector<int>> res1(n, vector<int>(3)), res2(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
      int h, w;
      cin >> h >> w;
      areas[i] = h * w;
      res1[i][0] = res2[i][0] = i;
      res1[i][1] = res2[i][1] = h;
      res1[i][2] = res2[i][2] = w;
    }
    sort(res1.begin(), res1.end(),
         [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
    sort(res2.begin(), res2.end(),
         [&](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
    while (q--) {
      ll ans = 0;
      int hs, hb, ws, wb;
      cin >> hs >> ws >> hb >> wb;
      int l = 0, r = n - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (res1[mid][1] > hs) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      int ihs = l;
      l = 0, r = n - 1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (res1[mid][1] < hb) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      int ihb = l;
      l = 0, r = n - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (res2[mid][2] > ws) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      int iws = l;
      l = 0, r = n - 1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (res2[mid][2] < wb) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      int iwb = l;
      unordered_map<int, int> mp;
      for (int i = ihs; i <= ihb; i++) {
        mp[res1[i][0]]++;
      }
      for (int i = iws; i <= iwb; i++) {
        mp[res2[i][0]]++;
      }
      for (auto e : mp) {
        if (e.second == 2) {
          ans += areas[e.first];
        }
      }
      cout << ans << '\n';
    }
  }

  return 0;
}
