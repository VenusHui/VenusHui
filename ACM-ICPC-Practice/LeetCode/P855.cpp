// 875. 爱吃香蕉的珂珂
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int l = 1, r = 1e9 + 1;
        function<bool(int)> check = [&] (int m) {
            int tmp = 0;
            for (int i = 0; i < size; i++) {
                if (m == 0) {
                    continue;
                }
                if (piles[i] % m == 0) {
                    tmp += piles[i] / m;
                }
                else {
                    tmp += piles[i] / m + 1;
                }
            }
            if (tmp <= h) {
                return true;
            }
            return false;
        };
        while (l < r) {
            int m = (l + r) >> 1;
            if (!check(m)) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }
};