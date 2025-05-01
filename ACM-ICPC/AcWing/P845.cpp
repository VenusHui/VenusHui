/**
 * @platform: AcWing
 * @problem: P845
 * @version: Toturial
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
  const string end = "12345678x";
  const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  string start;
  for (int i = 0; i < 9; i++) {
    string tmp;
    cin >> tmp;
    start += tmp;
  }
  function<bool(pair<int, int>)> check = [&](pair<int, int> pos) {
    return pos.first >= 0 && pos.first < 3 && pos.second >= 0 && pos.second < 3;
  };
  function<int(string)> bfs = [&](string s) {
    queue<string> q;
    unordered_map<string, int> mp;
    mp[start] = 0;
    q.push(start);
    while (!q.empty()) {
      string cnt = q.front();
      q.pop();
      int dist = mp[cnt];
      if (cnt == end)
        return dist;
      int idx = cnt.find('x');
      int x = idx / 3, y = idx % 3;
      for (auto &d : dir) {
        pair<int, int> next = make_pair(x + d.first, y + d.second);
        if (check(next)) {
          swap(s[idx], s[next.first * 3 + next.second]);
          if (!mp.count(s)) {
            mp[s] = dist + 1;
            q.push(s);
          }
          swap(s[idx], s[next.first * 3 + next.second]);
        }
      }
    }
    return -1;
  };
  cout << bfs(start) << '\n';

  return 0;
}
