// 2491. 划分技能点相等的团队
class Solution {
public:
  long long dividePlayers(vector<int> &skill) {
    int size = skill.size();
    sort(skill.begin(), skill.end());
    vector<pair<int, int>> res;
    int l = 0, r = size - 1;
    int std = skill[l] + skill[r];
    bool flag = true;
    while (l < r) {
      if (skill[l] + skill[r] == std) {
        res.push_back(make_pair(skill[l], skill[r]));
      } else {
        flag = false;
        break;
      }
      l++;
      r--;
    }
    long long ans = 0;
    if (flag) {
      for (auto &i : res) {
        ans += 1LL * i.first * i.second;
      }
    } else {
      ans = -1;
    }
    return ans;
  }
};