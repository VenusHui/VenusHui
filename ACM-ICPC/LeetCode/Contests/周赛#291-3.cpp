// 第三题 含最多 K 个可整除元素的子数组
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int size = nums.size(), mnum = 0;
        vector<int> res(size, 0), pre(size);
        for (int i = 0; i < size; i++) {
            if (nums[i] % p == 0) {
                res[i]++;
            }
        }
        partial_sum(res.begin(), res.end(), pre.begin());
        pre.insert(pre.begin(), 0);
        int ans = 0;
        for (int len = 1; len <= size; len++) {
            set<vector<int>> s;
            int l = 0, r = size - len;
            for (int i = l; i <= r; i++) {
                if (pre[i + len] - pre[i] <= k) {
                    vector<int> tmp;
                    for (int t = i; t < i + len; t++) {
                        tmp.push_back(nums[t]);
                    }
                    s.insert(tmp);
                }
            }
            ans += s.size();
        }
        return ans;
    }
};