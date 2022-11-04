// 2309. 兼具大小写的最好英文字母
class Solution {
public:
    string greatestLetter(string s) {
        vector<int> res1(26), res2(26);
        for (auto& it : s) {
            if (it >= 'a' && it <= 'z') {
                res1[it - 'a']++;
            }
            else if (it >= 'A' && it <= 'Z') {
                res2[it - 'A']++;
            }
        }
        int ans = -1;
        for (int i = 0; i < 26; i++) {
            if (res1[i] != 0 && res2[i] != 0) {
                ans = max(ans, i);
            }
        }
        if (ans == -1) {
            return "";
        }
        string a;
        a += char('A' + ans);
        return a;
    }
};