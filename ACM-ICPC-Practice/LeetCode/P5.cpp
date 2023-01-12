// 5. 最长回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 1)
            return s;
        vector<bool> tmp(size);
        vector<vector<bool>> dp;
        for (int i = 0; i < size; i++)
            dp.push_back(tmp);
        for (int i = 0; i < size; i++)
            dp[i][i] = true;
        for (int i = 0; i < size - 1; i++) {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = true;
        }
        for (int len = 2; len < size; len++) {
            for (int l = 0; l + len < size; l++) {
                int r = l + len;
                if (dp[l + 1][r - 1] && s[l] == s[r])
                    dp[l][r] = true;
            }
        }
        string ans;
        int len = 0, ll = 0, rr = 0;
        for (int l = 0; l < size; l++) {
            for (int r = l; r < size; r++) {
                if (dp[l][r] && r - l + 1 > len) {
                    len = r - l + 1;
                    ll = l;
                    rr = r;
                }
            }
        }
        for (int i = ll; i <= rr; i++)
            ans += s[i];
        return ans;
    }
};