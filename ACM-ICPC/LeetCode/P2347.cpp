// 2347. 最好的扑克手牌
class Solution {
public:
  string bestHand(vector<int> &ranks, vector<char> &suits) {
    const int maxn = ranks.size();
    bool flag = true;
    for (int i = 0; i < maxn; i++) {
      if (suits[i] != suits[0])
        flag = false;
    }
    if (flag)
      return "Flush";
    flag = false;
    int num = 0;
    map<int, int> mp;
    for (int i = 0; i < maxn; i++)
      mp[ranks[i]]++;
    for (auto &e : mp) {
      if (e.second >= 3)
        flag = true;
      if (e.second >= 2)
        num++;
    }
    if (flag)
      return "Three of a Kind";
    if (num)
      return "Pair";
    return "High Card";
  }
};