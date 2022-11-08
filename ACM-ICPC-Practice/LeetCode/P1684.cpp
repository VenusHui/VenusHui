// 1684. 统计一致字符串的数目
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> alphbet(26, false);
        for (auto& i : allowed) {
            alphbet[i - 'a'] = true;
        }
        int ans = 0;
        for (auto& s : words) {
            bool flag = true;
            for (auto& ch : s) {
                if (!alphbet[ch - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
};