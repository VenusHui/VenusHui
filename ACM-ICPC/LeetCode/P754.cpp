// 754. 到达终点数字
class Solution {
public:
    int reachNumber(int target) {
        int ans = 0;
        target = abs(target);
        while (target > 0) {
            ans++;
            target -= ans;
        }
        if (target == 0 || abs(target) % 2 == 0) {
            return ans;
        }
        return ans + 1 + ans % 2;
    }
};