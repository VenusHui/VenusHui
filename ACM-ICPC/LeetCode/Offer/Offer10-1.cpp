// 剑指 Offer 10- I. 斐波那契数列
class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int fib(int n) {
        if (n == 0) return 0;
        vector<int> ans(n + 1);
        ans[0] = 0, ans[1] = 1;
        for (int i = 2; i <= n; i++) {
            ans[i] = (ans[i - 1] + ans[i - 2]) % mod;
        }
        return ans[n] % mod;
    }
};