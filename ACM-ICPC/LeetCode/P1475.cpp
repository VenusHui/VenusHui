// 1475. 商品折扣后的最终价格
class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    int size = prices.size();
    vector<int> ans(size);
    for (int i = 0; i < size; i++) {
      ans[i] = prices[i];
      for (int j = i + 1; j < size; j++) {
        if (prices[j] <= prices[i]) {
          ans[i] -= prices[j];
          break;
        }
      }
    }
    return ans;
  }
};