// 2327. 知道秘密的人数
class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<long long>> res(n + 1, vector<long long>(3)); // num, delay, forget
        long long tmp = 1, fo = 0;
        for (int i = 1; i <= n; i++) {
            if (tmp != 0) {
                res[i][0] = tmp;
                res[i][1] = delay;
                res[i][2] = forget;
                tmp = 0;
            }
            fo = 0;
            for (int i = 1; i <= n; i++) {
                if (res[i][0] != 0) {
                    res[i][1]--;
                    res[i][2]--;
                    if (res[i][2] <= 0) {
                        if (res[i][2] == 0) {
                            fo += res[i][0] % mod;
                        }
                        res[i][0] = 0;
                    }
                    if (res[i][1] <= 0) {
                        tmp += res[i][0] % mod;
                    }
                }
            }
        }
        long long ans = fo % mod;
        for (int i = 1; i <= n; i++) {
            ans = (ans + res[i][0]) % mod;
        }
        
        return static_cast<int>(ans % mod);
    }
};