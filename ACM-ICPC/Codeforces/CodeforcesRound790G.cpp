/***********************************
 *  Codeforces Round #790 (Div. 4)
 *  G. White-Black Balanced Subtrees
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Date: 2022-05-11
 ***********************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
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
    vector<vector<int>> edge(n + 1);
    for (int i = 2; i <= n; i++) {
      int parent;
      cin >> parent;
      edge[parent].push_back(i);
    }
    vector<char> color(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> color[i];
    }
    int ans = 0;
    function<pair<int, int>(int)> dfs = [&](int cnt) {
      pair<int, int> tmp = make_pair(0, 0);
      if (color[cnt] == 'W') {
        tmp.first++;
      } else {
        tmp.second++;
      }
      for (auto &it : edge[cnt]) {
        pair<int, int> t = dfs(it);
        tmp.first += t.first;
        tmp.second += t.second;
      }
      if (tmp.first == tmp.second) {
        ans++;
      }
      return tmp;
    };
    dfs(1);
    cout << ans << '\n';
  }

  return 0;
}
