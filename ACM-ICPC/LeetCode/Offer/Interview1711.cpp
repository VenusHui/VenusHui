// 面试题 17.11. 单词距离
class Solution {
public:
  int findClosest(vector<string> &words, string word1, string word2) {
    int size = words.size();
    vector<int> pos1, pos2;
    for (int i = 0; i < size; i++) {
      if (words[i] == word1) {
        pos1.push_back(i);
      } else if (words[i] == word2) {
        pos2.push_back(i);
      }
    }
    int ans = 1e9 + 1;
    for (auto &a : pos1) {
      for (auto &b : pos2) {
        ans = min(ans, abs(a - b));
      }
    }
    return ans;
  }
};