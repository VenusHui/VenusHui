// 2293. 极大极小游戏
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while (n != 1) {
            vector<int> tmp(n / 2);
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) tmp[i] = min(nums[2 * i], nums[2 * i + 1]);
                if (i % 2 == 1) tmp[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = tmp, n /= 2;
        }
        return nums[0];
    }
};