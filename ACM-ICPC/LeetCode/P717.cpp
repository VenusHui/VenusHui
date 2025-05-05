// 717. 1比特与2比特字符
class Solution {
public:
  bool isOneBitCharacter(vector<int> &bits) {
    bool isOneBit = false;
    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
      if (bits[i] == 1) {
        isOneBit = false;
        i++;
      } else {
        isOneBit = true;
      }
    }
    return isOneBit;
  }
};