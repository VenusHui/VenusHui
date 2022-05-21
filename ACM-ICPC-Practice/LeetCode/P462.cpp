// 462. 最少移动次数使数组元素相等 II
class Solution {
private:
    inline int calc(vector<int>& nums, int pos) {
        int ans = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            ans += abs(nums[i] - nums[pos]);
        }
        return ans;
    }
public:
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if (size % 2 == 1) {
            return calc(nums, size / 2);
        }
        else {
            return min(calc(nums, size / 2), calc(nums, size / 2 - 1));
        }
    }
};