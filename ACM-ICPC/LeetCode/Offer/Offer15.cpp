// 剑指 Offer 15. 二进制中1的个数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n -= n & -n;
            ans++;
        }
        return ans;
    }
};