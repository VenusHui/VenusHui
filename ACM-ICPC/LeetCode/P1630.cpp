// 1630. 等差子数组
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = l[i]; j <= r[i]; j++) {
                tmp.push_back(nums[j]);
            }
            bool flag = true;
            if (tmp.size() <= 1) {
                ans[i] = true;
                continue;
            }
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < tmp.size() - 1; j++) {
                if (tmp[j] - tmp[j + 1] != tmp[0] - tmp[1]) {
                    flag = false;
                    break;
                }
            }
            ans[i] = flag;
        }
        return ans;
    }
};