// 2218. 从栈中取出 K 个硬币的最大面值和
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        int size = p.size();
        vector<vector<int>> dp(size + 1, vector<int>(k + 1));
        for (int i = 1; i <= size; i++) {
            int n = p[i - 1].size();
            for (int j = 1; j <= k; j++) {
                int cnt = 0;
                for (int x = 1; x <= n && x <= j; x++) {
                    cnt += p[i - 1][x - 1];
                    dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + cnt);
                }
            }
        }
        return dp[size][k];
    }
};