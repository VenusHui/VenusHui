// 2389. 和有限的最长子序列
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (pre[mid] <= queries[i]) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            ans[i] = l;
        }
        return ans;
    }
};