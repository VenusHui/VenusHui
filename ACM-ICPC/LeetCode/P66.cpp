// 66. 加一
// 模拟
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int size = digits.size();
    digits.at(size - 1)++;
    int i = size - 1;
    while (digits.at(i) == 10) {
      digits.at(i) = 0;
      i--;
      if (i < 0) {
        digits.insert(digits.begin(), 1);
        break;
      } else {
        digits.at(i)++;
      }
    }
    return digits;
  }
};

// 又写了一遍模拟
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int size = digits.size();
    for (int i = size - 1; i >= 0; i--) {
      digits[i]++;
      if (digits[i] < 10)
        break;
      else {
        digits[i] = 0;
        if (i == 0)
          digits.insert(digits.begin(), 1);
      }
    }
    return digits;
  }
};