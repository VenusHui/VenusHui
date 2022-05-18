// 6065. 按位与结果大于零的最长组合
class Solution {
private:
    inline void calc(vector<int>& ans, int num) {
        int pos = 0;
        while (num) {
            ans[pos++] += num % 2;
            num /= 2;
        }
    }
public:
    int largestCombination(vector<int>& candidates) {
        int size = candidates.size();
        vector<int> ans(32, 0);
        for (int i = 0; i < size; i++) {
            calc(ans, candidates[i]);
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res = max(res, ans[i]);
        }
        return res;
    }
};