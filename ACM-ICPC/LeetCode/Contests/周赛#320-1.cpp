// 6241. 数组中不等三元组的数目
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int size = nums.size(), ans = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (nums[i] != nums[j]) {
                    for (int k = j; k < size; k++) {
                        if (nums[k] != nums[i] && nums[k] != nums[j]) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};