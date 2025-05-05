// 剑指 Offer 12. 矩阵中的路径
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    bool ans = false;
    int n = board.size(), m = board[0].size();
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    function<void(pair<int, int>, string, vector<vector<bool>> &)> dfs =
        [&](pair<int, int> cnt, string s, vector<vector<bool>> &vis) {
          if (s == word) {
            ans = true;
            return;
          }
          if (cnt.first < 0 || cnt.second < 0 || cnt.first >= n ||
              cnt.second >= m)
            return;
          if (vis[cnt.first][cnt.second])
            return;
          int size = s.size();
          if (word[size] == board[cnt.first][cnt.second]) {
            s += word[size];
            vis[cnt.first][cnt.second] = true;
            for (auto &e : dir) {
              pair<int, int> nxt =
                  make_pair(cnt.first + e.first, cnt.second + e.second);
              dfs(nxt, s, vis);
            }
            vis[cnt.first][cnt.second] = false;
          }
        };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          string s;
          vector<vector<bool>> vis(n, vector<bool>(m, false));
          dfs(make_pair(i, j), s, vis);
          if (ans)
            return ans;
        }
      }
    }
    return false;
  }
};