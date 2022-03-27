// 6027. 统计数组中峰和谷的数量
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        for (int i = 1; i < size - 1; i++) {
            if (nums[i] == nums[i - 1])
                continue;
            int tmp = i;
            while (nums[tmp] == nums[i])
                tmp++;
            if (tmp >= size)
                break;
            if (nums[i] > nums[i - 1] && nums[i] > nums[tmp]) {
                ans++;
            }
            if (nums[i] < nums[i - 1] && nums[i] < nums[tmp]) {
                ans++;
            }
        }
        return ans;
    }
};