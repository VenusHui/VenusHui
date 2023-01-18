// 2527. 查询数组 Xor 美丽值
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = nums[0];
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            ans = ans xor nums[i];
        }
        return ans;
    }
};