// 1807. 替换字符串中的括号内容
class Solution {
public:
  string evaluate(string s, vector<vector<string>> &knowledge) {
    string ans;
    map<string, string> mp;
    for (auto &e : knowledge) {
      mp[e[0]] = e[1];
    }
    int size = s.size();
    string key;
    bool flag = false;
    for (int i = 0; i < size; i++) {
      if (s[i] == '(') {
        flag = true;
        continue;
      }
      if (s[i] == ')') {
        ans += mp.find(key) != mp.end() ? mp[key] : "?";
        flag = false;
        key = "";
        continue;
      }
      (flag ? key : ans) += s[i]; // 三目运算符表达式可以作为左值的啊
    }
    return ans;
  }
};