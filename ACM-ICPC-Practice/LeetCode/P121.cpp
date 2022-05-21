// 121. 买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int minp = prices[0], tmp = 0, ans = 0;
        for (int i = 0; i < size; i++) {
            tmp = prices[i] - minp;
            ans = max(ans, tmp);
            minp = min(minp, prices[i]);
        }
        return ans;
    }
};