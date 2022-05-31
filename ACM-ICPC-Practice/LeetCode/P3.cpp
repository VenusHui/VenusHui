// 3. 无重复字符的最长子串
// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_map<char, int> mp;
        int l = 0, r = 0, ans = 0;
        while (r < size) {
            char c = s[r];
            r++;
            mp[c]++;
            while (mp[c] > 1) {
                char d = s[l];
                l++;
                mp[d]--;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};