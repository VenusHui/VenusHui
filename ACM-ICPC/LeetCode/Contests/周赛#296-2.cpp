// 2294. 划分数组使最大差为 K
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.push_back(1e9 + 1);
        int ans = 0, tmp = nums[0];
        for (auto& it : nums) {
            if (it - tmp > k) {
                ans++;
                tmp = it;
            }
        }
        return ans;
    }
};