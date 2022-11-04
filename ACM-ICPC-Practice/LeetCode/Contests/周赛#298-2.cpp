// 2310. 个位数字为 K 的整数之和
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        if (k == 0) {
            if (num % 10 == 0) {
                return 1;
            }
            else {
                return -1;
            }
        }
        int ans = 1;
        num -= k;
        while (num % 10 != 0) {
            num -= k;
            if (num < 0) {
                return -1;
            }
            ans++;
        }
        return ans;
    }
};