// 2287. 重排字符形成目标字符串
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int ans = 1e9 + 1;
        vector<int> res(26), tar(26);
        for (auto& it : s) {
            res[it - 'a']++;
        }
        for (auto& it : target) {
            tar[it - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (tar[i] != 0) {
                ans = min(ans, res[i] / tar[i]);
            }
        }
        return ans;
    }
};