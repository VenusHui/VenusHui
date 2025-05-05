// 1217. 玩筹码
class Solution {
public:
  int minCostToMoveChips(vector<int> &position) {
    int ans = 0, size = position.size();
    int odd = 0, even = 0;
    for (int i = 0; i < size; i++) {
      if (position[i] % 2 == 0) {
        even++;
      } else {
        odd++;
      }
    }
    return min(odd, even);
  }
};