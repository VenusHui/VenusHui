/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest272D
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-08
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> res;
  int maxlen = sqrt(m) + 1;
  for (int i = 0; i <= maxlen; i++) {
    for (int j = 0; j <= maxlen; j++) {
      if (i * i + j * j == m) {
        res.push_back(make_pair(i, j));
        res.push_back(make_pair(-1 * i, j));
        res.push_back(make_pair(i, -1 * j));
        res.push_back(make_pair(-1 * i, -1 * j));
      }
    }
  }
  int size = res.size();
  // for (int i = 0; i < size; i++) {
  //     cout << res[i].first << " " << res[i].second << '\n';
  // }
  vector<vector<int>> ans(n, vector<int>(n, -1));
  ans[0][0] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    pair<int, int> cnt = q.front();
    q.pop();
    for (int i = 0; i < size; i++) {
      pair<int, int> nxt =
          make_pair(cnt.first + res[i].first, cnt.second + res[i].second);
      if (nxt.first >= 0 && nxt.first < n && nxt.second >= 0 &&
          nxt.second < n && ans[nxt.first][nxt.second] == -1) {
        ans[nxt.first][nxt.second] = ans[cnt.first][cnt.second] + 1;
        q.push(make_pair(nxt.first, nxt.second));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}
