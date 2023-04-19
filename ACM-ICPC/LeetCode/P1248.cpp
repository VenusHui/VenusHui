// 1248. 统计「优美子数组」
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1] % 2;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += upper_bound(pre.begin(), pre.end(), pre[i] + k) - lower_bound(pre.begin(), pre.end(), pre[i] + k);
        }
        return ans;
    }
};