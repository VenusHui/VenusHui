// 第二题 必须拿起的最小连续卡牌数
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < size; i++) {
            if (mp.find(cards[i]) == mp.end()) {
                vector<int> tmp(1, i);
                mp.insert(make_pair(cards[i], tmp));
            }
            else {
                mp.find(cards[i])->second.push_back(i);
            }
        }
        int ans = 1e5 + 1;
        for (auto &it : mp) {
            int vsize = it.second.size();
            for (int i = 0; i < vsize - 1; i++) {
                ans = min(ans, it.second[i + 1] - it.second[i] + 1);
            }
        }
        if (ans > 1e5) {
            ans = -1;
        }
        return ans;
    }
};