// 937. 重新排列日志文件
class Solution {
public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    vector<string> ans, dig;
    set<pair<string, string>> s;
    int size = logs.size();
    for (int i = 0; i < size; i++) {
      bool flag = false;
      int isize = logs[i].size();
      for (int j = 0; j < isize; j++) {
        if (flag) {
          if (logs[i][j] >= '0' && logs[i][j] <= '9') {
            dig.push_back(logs[i]);
          } else {
            s.insert(make_pair(logs[i].substr(j, isize - j), logs[i]));
          }
          break;
        }
        if (logs[i][j] == ' ') {
          flag = true;
        }
      }
    }
    for (auto &it : s) {
      ans.push_back(it.second);
    }
    for (auto &it : dig) {
      ans.push_back(it);
    }
    return ans;
  }
};