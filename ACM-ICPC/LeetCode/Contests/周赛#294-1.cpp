// 2278. 字母在字符串中的百分比
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int size = s.size(), ans = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == letter) {
                ans++;
            }
        }
        return ans * 100 / size;
    }
};