// 744. 寻找比目标字母大的最小字母
class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int size = letters.size();
    if (target >= letters[size - 1]) {
      return letters[0];
    }
    int l = 0, r = size - 1;
    while (l < r) {
      int m = (l + r) >> 1;
      if (letters[m] <= target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return letters[l];
  }
};
