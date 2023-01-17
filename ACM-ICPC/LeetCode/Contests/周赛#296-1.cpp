// 2293. 极大极小游戏
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> tmp(nums.size() / 2);
            for (int i = 0; i < nums.size() - 1; i++) {
                if (i % 4 == 0) {
                    tmp[i / 2] = min(nums[i], nums[i + 1]);
                }
                else {
                    tmp[i / 2] = max(nums[i], nums[i + 1]);
                }
                i++;
            }
            nums = tmp;
        }
        return nums[0];
    }
};