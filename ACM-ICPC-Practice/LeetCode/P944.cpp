// 944. 删列造序
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int row = strs.size(), col = strs[0].size();
        for (int i = 0; i < col; i++) {
            bool flag = true;
            for (int j = 1; j < row; j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                ans++;
            }
        }
        return ans;
    }
};