// 2185. 统计包含给定前缀的字符串
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto& s : words) {
            if (s.size() >= pref.size() && s.substr(0, pref.size()) == pref) {
                ans++;
            }
        }
        return ans;
    }
};