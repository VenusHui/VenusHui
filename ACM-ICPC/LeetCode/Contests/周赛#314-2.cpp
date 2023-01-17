// 2433. 找出前缀异或的原始数组
class Solution {
private:
    const int maxn = 30;
    inline int calc(int a, int b) {
        vector<int> ab(maxn), bb(maxn);
        int pos = 0;
        while (a) {
            ab[pos++] = a % 2;
            a /= 2;
        }
        pos = 0;
        while (b) {
            bb[pos++] = b % 2;
            b /= 2;
        }
        vector<int> ans(maxn);
        for (int i = 0; i < maxn; i++) {
            if (ab[i] == 1) {
                if (bb[i] == 1) {
                    ans[i] = 0;
                }
                else {
                    ans[i] = 1;
                }
            }
            else {
                ans[i] = bb[i];
            }
        }
        int res = 0;
        for (int i = 0; i < maxn; i++) {
            res += (ans[i] << i);
        }
        return res;
    }
public:
    vector<int> findArray(vector<int>& pref) {
        int size = pref.size();
        vector<int> ans(size);
        ans[0] = pref[0];
        int num = pref[0];
        for (int i = 1; i < size; i++) {
            ans[i] = calc(pref[i], num);
            num ^= ans[i];
        }
        return ans;
    }
};