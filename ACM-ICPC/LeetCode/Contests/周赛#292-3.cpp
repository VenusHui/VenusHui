// 6058. 统计打字方案数
class Solution {
private:
    const long long mod = 1e9 + 7;
    vector<int> keys = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    inline long long calc(int num, int size) {
        long long ans = 0;
        vector<long long> dp(num + 1);
        dp[0] = 1;
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= size; j++) {
                if (i - j >= 0) {
                    dp[i] =(dp[i] + dp[i - j]) % mod;
                }
            }
        }
        return dp[num];
    }
public:
    int countTexts(string pressedKeys) {
        long long ans = 1;
        pressedKeys += "&";
        int size = pressedKeys.size(), tmp = 1;
        for (int i = 0; i < size - 1; i++) {
            if (pressedKeys[i] == pressedKeys[i + 1]) {
                tmp++;
            }
            else if (pressedKeys[i] != pressedKeys[i + 1]) {
                ans = (ans * calc(tmp, keys[pressedKeys[i] - '0'])) % mod;
                tmp = 1;
            }
        }
        return static_cast<int>(ans % mod);
    }
};