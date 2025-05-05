/***********************************
 *  Codeforces Round #787 (Div. 3)
 *  F. Vlad and Unfinished Business
 *  Writer: VenusHui
 *  Version: Tutorial Version
 *  Date: 2022-05-10
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

// Method : DFS子树标记

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    vector<bool> things(n + 1, false);
    for (int i = 0; i < k; i++) {
      int num;
      cin >> num;
      things[num] = true;
    }
    things[y] = true;
    vector<vector<int>> path(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int v, u;
      cin >> v >> u;
      path[v].push_back(u);
      path[u].push_back(v);
    }

    // 要找所有需要走的点
    int ans = n;
    vector<int> depth(n + 1); // 标记每个点的深度
    function<int(int, int)> dfs = [&](int cnt, int pre) {
      int tot = 0; // 表示cnt的子树要走的点的数量
      for (auto &it : path[cnt]) {
        if (it == pre) { // 叶子结点
          continue;
        }
        depth[it] = depth[cnt] + 1; // 标记深度
        tot += dfs(it, cnt);
      }
      // 如果子树不需要走且cnt也不需要走，则从ans中把cnt去掉
      if (!tot && !things[cnt]) {
        ans--;
      }
      return tot + (things[cnt] == true); // 返回子树要走的点的数量 + cnt
    };
    dfs(x, -1);
    cout << 2 * (ans - 1) - depth[y] << '\n';
  }

  return 0;
}
