// 剑指 Offer 58 - II. 左旋转字符串
class Solution {
public:
  string reverseLeftWords(string s, int n) {
    return s.substr(n) + s.substr(0, n);
  }
};