// 2379. 得到 K 个黑块的最少涂色次数
class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int ans = 0x3f3f3f3f, size = blocks.size();
    for (int i = 0; i < size; i++) {
      int tmp = 0, num = 0;
      for (int j = i; j < size; j++) {
        if (blocks[j] == 'B')
          num++;
        else
          tmp++, num++;
        if (num == k)
          break;
      }
      if (num == k)
        ans = min(ans, tmp);
    }
    return ans;
  }
};