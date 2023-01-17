// 122.买卖股票的最佳时机 II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int size = prices.size();
        for (int i = 0; i < size - 1; i++) {
            if (prices[i] <= prices[i + 1]) {
                ans += prices[i + 1] - prices[i];
            }
        }
        return ans;
    }
};