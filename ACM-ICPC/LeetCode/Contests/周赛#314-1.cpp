// 2432. 处理用时最长的那个任务的员工
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int size = logs.size();
        int ans = logs[0][0], time = logs[0][1];
        for (int i = 1; i < size; i++) {
            if (logs[i][1] - logs[i - 1][1] > time) {
                time = logs[i][1] - logs[i - 1][1];
                ans = logs[i][0];
            }
            else if (logs[i][1] - logs[i - 1][1] == time) {
                ans = min(ans, logs[i][0]);
            }
        }
        return ans;
    }
};