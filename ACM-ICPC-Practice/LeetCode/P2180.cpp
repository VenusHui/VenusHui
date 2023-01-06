// 2180. 统计各位数字之和为偶数的整数个数
class Solution {
public:
    int countEven(int num) {
        function<int(int)> calc = [&] (int n) {
            int ans = 0;
            while (n) {
                ans += n % 10;
                n /= 10;
            }
            return ans;
        };
        int res = 0;
        for (int i = 1; i <= num; i++) {
            if (calc(i) % 2 == 0) {
                res++;
            }
        }
        return res;
    }
};