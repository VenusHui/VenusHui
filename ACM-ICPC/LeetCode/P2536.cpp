// 2536. 子矩阵元素加 1
class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
    vector<vector<int>> pre(n + 1, vector<int>(n + 1));
    // 向 (x1, y1) 到 (x2, y2) 区域内的数都加上 c
    function<void(int, int, int, int, int)> insert = [&](int x1, int y1, int x2,
                                                         int y2, int c) {
      pre[x1][y1] += c, pre[x2 + 1][y1] -= c, pre[x1][y2 + 1] -= c,
          pre[x2 + 1][y2 + 1] += c;
    };
    for (auto &e : queries) {
      insert(e[0], e[1], e[2], e[3], 1);
    }
    // 计算最终矩阵
    vector<vector<int>> ans(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] +
                    pre[i - 1][j - 1];
      }
    }
    ans.erase(ans.begin());
    for (auto &e : ans)
      e.erase(e.begin());
    return ans;
  }
};