// 383. 赎金信
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int rsize = ransomNote.size(), msize = magazine.size();
    vector<int> res(26);
    for (int i = 0; i < msize; i++) {
      res[magazine[i] - 'a']++;
    }
    for (int i = 0; i < rsize; i++) {
      res[ransomNote[i] - 'a']--;
      if (res[ransomNote[i] - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};