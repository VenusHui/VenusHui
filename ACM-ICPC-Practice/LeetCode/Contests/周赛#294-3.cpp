// 2280. 表示一个折线图的最少线段数
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int size = stockPrices.size(), ans = 1;
        if (size == 1) {
            return 0;
        }
        sort(stockPrices.begin(), stockPrices.end());
        vector<pair<int, int>> res(size - 1);
        for (int i = 1; i < size; i++) {
            res[i - 1] = make_pair(stockPrices[i][1] - stockPrices[i - 1][1], stockPrices[i][0] - stockPrices[i - 1][0]);
        }
        for (int i = 1; i < size - 1; i++) {
            if (1LL * res[i].first * res[i - 1].second != 1LL * res[i].second * res[i - 1].first) {
                ans++;
            }
        }
        return ans;
    }
};