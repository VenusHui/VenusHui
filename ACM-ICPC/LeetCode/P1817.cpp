// 1817. 查找用户活跃分钟数
class Solution {
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
    vector<int> ans(k);
    map<int, set<int>> mp;
    for (auto &e : logs)
      mp[e[0]].insert(e[1]);
    for (auto &e : mp)
      ans[e.second.size() - 1]++;
    return ans;
  }
};