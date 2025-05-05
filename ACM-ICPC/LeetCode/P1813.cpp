// 1813. 句子相似性 III
class Solution {
public:
  vector<string_view> split(const string &str, char target) {
    vector<string_view> res;
    string_view s(str);
    int pos = 0;
    while (pos < s.size()) {
      while (pos < s.size() && s[pos] == target)
        pos++;
      int start = pos;
      while (pos < s.size() && s[pos] != target)
        pos++;
      if (pos > start)
        res.emplace_back(s.substr(start, pos - start));
    }
    return res;
  }

  bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string_view> words1 = split(sentence1, ' ');
    vector<string_view> words2 = split(sentence2, ' ');
    int i = 0, j = 0;
    while (i < words1.size() && i < words2.size() && words1[i] == words2[i])
      i++;
    while (j < words1.size() - i && j < words2.size() - i &&
           words1[words1.size() - j - 1] == (words2[words2.size() - j - 1]))
      j++;
    return i + j == min(words1.size(), words2.size());
  }
};
