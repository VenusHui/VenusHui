// 1658. 将 x 减到 0 的最小操作数
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();
        vector<int> front(size + 1, 0), end(size + 1, 0);
        front[1] = nums[0], end[1] = nums[size - 1];
        for (int i = 1; i <= size; i++) {
            front[i] = front[i - 1] + nums[i - 1];
            end[i] = end[i - 1] + nums[size - i];
        }
        int ans = 1 << 30;
        for (int i = 0; i <= size; i++) {
            int l = 0, r = size;
            while (l < r) {
                int m = (l + r + 1) >> 1;
                if (end[m] + front[i] <= x) {
                    l = m;
                }
                else {
                    r = m - 1;
                }
            }
            if (i + l <= size && front[i] + end[l] == x) {
                ans = min(ans, i + l);
            }
        }
        if (ans > 1e5) {
            return -1;
        }
        return ans;
    }
};