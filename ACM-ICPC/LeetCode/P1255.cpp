// 1255. 得分最高的单词集合
class Solution {
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    int size = words.size();
    map<char, int> mp;
    for (auto &e : letters)
      mp[e]++;
    function<bool(string)> check = [&](string s) {
      map<char, int> tmp;
      for (auto &e : s)
        tmp[e]++;
      for (auto &e : tmp)
        if (mp[e.first] < e.second)
          return false;
      return true;
    };
    function<int(string)> calc = [&](string s) {
      int scr = 0;
      for (auto &e : s) {
        scr += score[e - 'a'];
        mp[e]--;
      }
      return scr;
    };
    function<void(string)> back = [&](string s) {
      for (auto &e : s)
        mp[e]++;
    };
    int ans = 0;
    function<void(int, int)> dfs = [&](int idx, int scr) {
      if (idx >= size) {
        ans = max(ans, scr);
        return;
      }
      dfs(idx + 1, scr);
      if (check(words[idx])) {
        dfs(idx + 1, scr + calc(words[idx]));
        back(words[idx]);
      }
    };
    dfs(0, 0);
    return ans;
  }
};