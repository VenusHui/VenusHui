// 5235. 找出输掉零场或一场比赛的玩家
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        int size = matches.size();
        map<int, int> w, l;
        for (int i = 0; i < size; i++) {
            if (w.find(matches[i][0]) == w.end()) {
                w.insert(make_pair(matches[i][0], 1));
            }
            else {
                w.find(matches[i][0])->second++;
            }
            if (l.find(matches[i][1]) == l.end()) {
                l.insert(make_pair(matches[i][1], 1));
            }
            else {
                l.find(matches[i][1])->second++;
            }
        }
        for (map<int, int>::iterator it = w.begin(); it != w.end(); it++) {
            if (l.find(it->first) == l.end()) {
                ans[0].push_back(it->first);
            }
        }
        for (map<int, int>::iterator it = l.begin(); it != l.end(); it++) {
            if (it->second == 1) {
                ans[1].push_back(it->first);
            }
        }
        return ans;
    }
};