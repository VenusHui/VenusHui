// 2490. 回环句
class Solution {
public:
  bool isCircularSentence(string sentence) {
    int size = sentence.size();
    vector<char> res;
    for (int i = 0; i < size; i++) {
      if (i == size - 1) {
        res.push_back(sentence[i]);
        res.push_back(sentence[0]);
      }
      if (sentence[i] == ' ') {
        res.push_back(sentence[i - 1]);
        res.push_back(sentence[i + 1]);
      }
    }
    bool flag = true;
    int rsize = res.size();
    for (int i = 0; i < rsize; i += 2) {
      if (res[i] != res[i + 1]) {
        flag = false;
        break;
      }
    }
    return flag;
  }
};

class Solution {
public:
  bool isCircularSentence(string sentence) {
    vector<string> words;
    int pos = 0;
    string s(sentence);
    while (pos < s.size()) {
      while (pos < s.size() && s[pos] == ' ')
        pos++;
      int start = pos;
      while (pos < s.size() && s[pos] != ' ')
        pos++;
      if (pos > start)
        words.push_back(s.substr(start, pos - start));
    }
    bool ans = true;
    int size = words.size();
    for (int i = 0; i < size; i++) {
      if (i != 0 && words[i][0] != words[i - 1][words[i - 1].size() - 1]) {
        ans = false;
        break;
      }
      if (i == size - 1 && words[i][words[i].size() - 1] != words[0][0]) {
        ans = false;
        break;
      }
    }
    return ans;
  }
};
