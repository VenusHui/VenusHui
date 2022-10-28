// 1235. 规划兼职工作
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int size = profit.size();
        vector<vector<int>> res(size);
        for (int i = 0; i < size; i++) {
            res[i] = {
                startTime[i],
                endTime[i],
                profit[i]
            };
        }
        sort(res.begin(), res.end(), [&] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> dp(size + 1);
        for (int i = 1; i <= size; i++) {
            dp[i] = max(dp[i - 1], res[i - 1][2]);
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (res[mid][1] <= res[i - 1][0]) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            if (res[l][1] <= res[i - 1][0]) {
                dp[i] = max(dp[i - 1], dp[l + 1] + res[i - 1][2]);
            }
        }
        return dp[size];
    }
};