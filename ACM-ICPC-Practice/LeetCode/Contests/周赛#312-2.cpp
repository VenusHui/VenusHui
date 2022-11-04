// 2419. 按位与最大的最长子数组
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        int num = nums[0];
        for (int i = 0; i < size; i++) {
            num = max(num, nums[i]);
        }
        int ans = 0, tmp = 0;
        for (int i = 0; i < size; i++) {
            if ((nums[i] & num) == num) {
                tmp++;
            }
            else {
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
        ans = max(ans, tmp);
        return ans;
    }
};