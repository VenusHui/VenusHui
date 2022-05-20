// 5236. 美化数组的最少删除数
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        for (int i = 1; i < size; i++) {
            if ((i - 1 - ans) % 2 == 0 && nums[i] == nums[i - 1]) {
                cout << nums[i - 1] << '\n';
                ans++;
            }
        }
        if ((size - ans) % 2 != 0) {
            ans++;
        }
        return ans;
    }
};