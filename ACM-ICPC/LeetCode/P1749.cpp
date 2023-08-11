// 1749. 任意子数组和的绝对值的最大值
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_max(n), dp_min(n);
        dp_max[0] = dp_min[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp_max[i] = max(nums[i], dp_max[i - 1] + nums[i]);
            dp_min[i] = min(nums[i], dp_min[i - 1] + nums[i]);
        }
        return max(abs(*max_element(dp_max.begin(), dp_max.end())), abs(*min_element(dp_min.begin(), dp_min.end())));
    }
};
