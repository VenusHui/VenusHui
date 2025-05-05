// 14. 最长公共前缀
class Solution {
private:
  const int maxn = 26;
  vector<pair<vector<int>, int>> trie;
  function<void(string)> insert = [&](string s) {
    int pos = 0;
    for (auto &e : s) {
      if (trie[pos].first[e - 'a'] == 0) {
        trie[pos].first[e - 'a'] = trie.size();
        trie.push_back(make_pair(vector<int>(maxn), 0));
      }
      pos = trie[pos].first[e - 'a'];
      trie[pos].second++;
    }
  };

public:
  string longestCommonPrefix(vector<string> &strs) {
    int n = strs.size();
    trie = vector<pair<vector<int>, int>>(1, make_pair(vector<int>(maxn), 0));
    for (auto &e : strs)
      insert(e);
    int pos = 0;
    string ans;
    bool flag = true;
    while (flag) {
      flag = false;
      for (int i = 0; i < maxn; i++) {
        if (trie[pos].first[i] != 0 && trie[trie[pos].first[i]].second == n) {
          flag = true;
          ans += char(i + 'a');
          pos = trie[pos].first[i];
          break;
        }
      }
    }
    return ans;
  }
};