// 2302. 统计得分小于 K 的子数组数目
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int size = nums.size();
        vector<long long> pre(size);
        pre[0] = nums[0];
        for (int i = 1; i < size; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        pre.insert(pre.begin(), 0);
        vector<long long> dp(size);
        for (int i = 0; i < size; i++) {
            int right = i;
            int l = 0, r = right;
            while (l < r) {
                int m = (l + r) >> 1;
                long long cnt = 1LL * (pre[right + 1] - pre[m]) * (right - m + 1);
                if (cnt >= k) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            if (1LL * (pre[right + 1] - pre[l]) * (right - l + 1) < k) {
                ans += (right - l + 1);
            }
            else {
                ans += (right - l);
            } 
        }
        return ans;
    }
};
