// 2395. 和相等的子数组
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for (int i = 0; i < n - 1; ++i) {
            int sum = nums[i] + nums[i + 1];
            if (seen.count(sum)) {
                return true;
            }
            seen.insert(sum);
        }
        return false;
    }
};
