// 476. 数字的补数
// 位运算，异或
class Solution {
public:
  int findComplement(int num) {
    int highbit = 0;
    for (int i = 1; i <= 30; ++i) { // 找到最高位
      if (num >= (1 << i)) {
        highbit = i;
      } else {
        break;
      }
    }
    int mask =
        (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1); // 进行特判
    return num ^ mask; // 与11111111进行异或
  }
};
