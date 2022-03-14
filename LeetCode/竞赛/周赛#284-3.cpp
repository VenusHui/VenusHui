// 5227. K 次操作后最大化顶端元素
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 1 && k % 2 == 1)
            return -1;
        if (k == 1)
            return nums[1];
        if (k == 0)
            return nums[0];
        int ans = nums[0];
        int i;
        for (i = 0; i < size && i < k - 1; i++)
            ans = max(ans, nums[i]);
        int tmp = -1;
        if (i + 1 < size)
            tmp = nums[i + 1];
        return max(ans, tmp);
    }
};