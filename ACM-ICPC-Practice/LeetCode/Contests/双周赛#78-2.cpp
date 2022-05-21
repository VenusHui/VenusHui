// 6067. 分割数组的方案数
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int size = nums.size();
        long long sum = 0;
        vector<long long> pre(size);
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            pre[i] = sum;
        }
        int ans = 0;
        for (int i = 0; i < size - 1; i++) {
            if (pre[i] >= sum - pre[i]) {
                ans++;
            }
        }
        return ans;
    }
};