// 942. 增减字符串匹配
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.size();
        vector<int> ans(size + 1);
        pair<int, int> cnt = make_pair(0, 0);
        for (int i = 0; i < size; i++) {
            if (s[i] == 'I') {
                ans[i + 1] = ++cnt.second;
            }
            else {
                ans[i + 1] = --cnt.first;
            }
        }
        for (int i = 0; i <= size; i++) {
            ans[i] -= cnt.first;
        }
        return ans;
    }
};