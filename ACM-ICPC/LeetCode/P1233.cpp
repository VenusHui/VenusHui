// 1233. 删除子文件夹
class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    function<bool(string, string)> check = [&](string a, string b) {
      if (a.size() >= b.size())
        return false;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
          return false;
      }
      return true;
    };
    vector<string> ans;
    sort(folder.begin(), folder.end());
    string cnt = folder[0] + '/';
    for (auto &e : folder) {
      if (!check(cnt, e)) {
        ans.push_back(e);
        cnt = e + '/';
      }
    }
    return ans;
  }
};