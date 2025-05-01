// 764. 最大加号标志
// TLE
class Solution {
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    vector<vector<int>> grid(n, vector<int>(n, 1));
    for (auto &e : mines) {
      grid[e[0]][e[1]] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          continue;
        }
        int cnt = 250, tmp = 0, count = 0;
        // left
        for (int k = j; k >= 0 && count <= cnt; k--, count++) {
          if (grid[i][k] == 1) {
            tmp++;
          } else {
            break;
          }
        }
        cnt = min(cnt, tmp);
        tmp = 0;
        count = 0;
        // right
        for (int k = j; k < n && count <= cnt; k++, count++) {
          if (grid[i][k] == 1) {
            tmp++;
          } else {
            break;
          }
        }
        cnt = min(cnt, tmp);
        tmp = 0;
        count = 0;
        // above
        for (int k = i; k >= 0 && count <= cnt; k--, count++) {
          if (grid[k][j] == 1) {
            tmp++;
          } else {
            break;
          }
        }
        cnt = min(cnt, tmp);
        tmp = 0;
        count = 0;
        // down
        for (int k = i; k < n && count <= cnt; k++, count++) {
          if (grid[k][j] == 1) {
            tmp++;
          } else {
            break;
          }
        }
        cnt = min(cnt, tmp);
        ans = max(ans, cnt);
      }
    }
    return ans;
  }
};

// AC
class Solution {
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    vector<vector<int>> grid(n, vector<int>(n, 1));
    for (auto &e : mines) {
      grid[e[0]][e[1]] = 0;
    }
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(n, vector<int>(4, 0)));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          dp[i][j][0]++;
          if (j != 0) {
            dp[i][j][0] += dp[i][j - 1][0];
          }
        }
      }
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 1) {
          dp[i][j][1]++;
          if (j != n - 1) {
            dp[i][j][1] += dp[i][j + 1][1];
          }
        }
      }
    }
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (grid[i][j] == 1) {
          dp[i][j][2]++;
          if (i != 0) {
            dp[i][j][2] += dp[i - 1][j][2];
          }
        }
      }
      for (int i = n - 1; i >= 0; i--) {
        if (grid[i][j] == 1) {
          dp[i][j][3]++;
          if (i != n - 1) {
            dp[i][j][3] += dp[i + 1][j][3];
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int cnt = 1 << 30;
        for (int k = 0; k < 4; k++) {
          cnt = min(cnt, dp[i][j][k]);
        }
        ans = max(ans, cnt);
      }
    }
    return ans;
  }
};