// 396. 旋转函数
// Tuturial Version
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size = nums.size();
        int ans = 0, sum = 0;
        for (int i = 0; i < size; i++) {
            ans += (i * nums[i]);
            sum += nums[i];
        }
        int tmp, cnt = ans;
        for (int i = size - 1; i >= 0; i--) {
            tmp = cnt + sum - size * nums[i];
            ans = max(ans, tmp);
            cnt = tmp;
        }
        return ans;
    }
};