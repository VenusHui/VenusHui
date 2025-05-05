/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#797D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-06-07
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s += "$";
    vector<pair<int, int>> res;
    bool flag = s[0] == 'B', ok = false;
    int start = 0, len = 0;
    for (int i = 0; i <= n; i++) {
      if (s[i] == 'B') {
        if (!flag) {
          start = i;
        }
        flag = true;
        len++;
        if (len >= k) {
          ok = true;
          break;
        }
      } else if (s[i] != 'B' && flag) {
        res.push_back(make_pair(start, len));
        start = i + 1;
        len = 0;
        flag = false;
      }
    }
    if (ok) {
      cout << "0" << '\n';
      continue;
    }
    int size = res.size();
    if (size == 0) {
      cout << k << '\n';
      continue;
    }
    vector<int> sub(size), pre(size);
    sub[0] = res[0].first - 0;
    for (int i = 1; i < size; i++) {
      sub[i] = res[i].first - (res[i - 1].first + res[i - 1].second);
    }
    pre[0] = sub[0];
    for (int i = 1; i < size; i++) {
      pre[i] = pre[i - 1] + sub[i];
    }
    int ans = 1e9 + 1;
    for (int i = 0; i < size; i++) {
      int tmp = res[i].first + k - 1;
      int l = 0, r = size - 1;
      while (l < r) {
        int m = (l + r + 1) >> 1;
        if (res[m].first <= tmp) {
          l = m;
        } else {
          r = m - 1;
        }
      }
      if (res[l].first + res[l].second - 1 >= tmp) {
        ans = min(ans, pre[l] - pre[i]);
      } else {
        ans = min(ans,
                  pre[l] - pre[i] + tmp - (res[l].first + res[l].second - 1));
      }
    }
    if (ans < 0) {
      cout << "0" << '\n';
    } else {
      cout << ans << '\n';
    }
  }

  return 0;
}
