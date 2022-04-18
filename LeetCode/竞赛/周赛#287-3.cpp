// 2226. 每个小孩最多能分到多少糖果
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int size = candies.size();
        int l = 0, r = 1e7 + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            long long num = 0;
            for (int i = 0; i < size; i++) {
                num += candies[i] / m;
            }
            if (num < k) {
                r = m;
            }
            else {
                l = m;
            }
        }
        return l;
    }
};