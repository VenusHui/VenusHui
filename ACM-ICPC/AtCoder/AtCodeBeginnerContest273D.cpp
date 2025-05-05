/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest273D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-15
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int h, w;
  pair<int, int> cnt;
  cin >> h >> w >> cnt.first >> cnt.second;
  int n;
  cin >> n;
  vector<pair<int, int>> walls(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    walls[i] = make_pair(x, y);
  }
  vector<pair<int, int>> fwalls = walls, swalls = walls;
  sort(fwalls.begin(), fwalls.end(),
       [&](pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; });
  sort(swalls.begin(), swalls.end(), [&](pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
  });
  int q;
  cin >> q;
  while (q--) {
    string d;
    int len;
    cin >> d >> len;
    pair<int, int> direct = make_pair(0, 0);
    if (d == "L") {
      direct.second = -1 * len;
      int l = 0, r = n - 1;
      if (swalls[l].second < cnt.second) {
        // cout << "WALL " << swalls[l].first << " " << swalls[l].second << " ";
        cnt.second = max(cnt.second + direct.second, swalls[l].second);
      } else {
        cnt.second = max(cnt.second + direct.second, 1);
      }
    } else if (d == "U") {
      direct.first = -1 * len;
      int l = 0, r = n - 1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (fwalls[mid].first < cnt.first) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      if (fwalls[l].first < cnt.first) {
        // cout << "WALL " << fwalls[l].first << " " << fwalls[l].second << " ";
        cnt.first = max(cnt.first + direct.first, fwalls[l].first);
      } else {
        cnt.first = max(cnt.first + direct.first, 1);
      }
    } else if (d == "R") {
      direct.second = 1 * len;
      int l = 0, r = n - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (swalls[mid].second > cnt.second) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if (swalls[l].second > cnt.second) {
        // cout << "WALL " << swalls[l].first << " " << swalls[l].second << " ";
        cnt.second = min(cnt.second + direct.second, swalls[l].second);
      } else {
        cnt.second = min(cnt.second + direct.second, w);
      }
    } else if (d == "D") {
      direct.first = 1 * len;
      int l = 0, r = n - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (fwalls[mid].first > cnt.first) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if (fwalls[l].first > cnt.first) {
        // cout << "WALL " << fwalls[l].first << " " << fwalls[l].second << " ";
        cnt.first = min(cnt.first + direct.first, fwalls[l].first);
      } else {
        cnt.first = min(cnt.first + direct.first, h);
      }
    }
    cout << cnt.first << " " << cnt.second << '\n';
  }

  return 0;
}
