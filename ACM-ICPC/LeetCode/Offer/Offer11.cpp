// 剑指 Offer 11. 旋转数组的最小数字
class Solution {
public:
  int minArray(vector<int> &numbers) {
    int size = numbers.size();
    int ll = 0, rr = size - 1;
    while (ll < rr) {
      int mid = (rr - ll) / 2 + ll;
      if (numbers[mid] == numbers[rr]) {
        rr--;
      } else if (numbers[mid] < numbers[rr]) {
        rr = mid;
      } else {
        ll = mid + 1;
      }
    }
    return numbers[rr];
  }
};