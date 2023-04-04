// 1638. 统计只差一个字符的子串数目
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        int ssize = s.size(), tsize = t.size();
        for (int i = 0; i < ssize; i++) {
            for (int j = 0; j < tsize; j++) {
                int diff = 0;
                for (int p = i, q = j; p < ssize && q < tsize; p++, q++) {
                    if (s[p] != t[q]) diff++;
                    if (diff == 1) ans++;
                    if (diff > 1) break;
                }
            }
        }
        return ans;
    }
};