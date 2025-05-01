/**
 * @platform: AcWing
 * @problem: P844
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-02-13
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<bool>> flag(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  function<bool(int, int)> check = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  int ans = 0;
  queue<tuple<int, int, int>> q;
  q.push(make_tuple(0, 0, 0));
  while (!q.empty()) {
    tuple<int, int, int> cnt = q.front();
    q.pop();
    if (get<0>(cnt) == n - 1 && get<1>(cnt) == m - 1) {
      ans = get<2>(cnt);
      break;
    }
    if (flag[get<0>(cnt)][get<1>(cnt)])
      continue;
    flag[get<0>(cnt)][get<1>(cnt)] = true;
    for (auto &d : dir) {
      tuple<int, int, int> next = make_tuple(
          get<0>(cnt) + d.first, get<1>(cnt) + d.second, get<2>(cnt) + 1);
      if (check(get<0>(next), get<1>(next)) &&
          grid[get<0>(next)][get<1>(next)] == 1) {
        q.push(next);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
