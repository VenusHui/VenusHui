// 1790. 仅执行一次字符串交换能否使两个字符串相等
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int size = s1.size();
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            if (s1[i] != s2[i]) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0 || ans.size() == 2 && s1[ans[0]] == s2[ans[1]] && s1[ans[1]] == s2[ans[0]]) {
            return true;
        }
        return false;
    }
};