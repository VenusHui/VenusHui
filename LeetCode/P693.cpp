// 693. 交替位二进制数
class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> res;
        while (n) {
            res.push_back(n % 2);
            n /= 2;
        }
        int size = res.size();
        bool ans = true;
        for (int i = 0; i < size - 1; i++) {
            if (res[i] == res[i + 1]) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};