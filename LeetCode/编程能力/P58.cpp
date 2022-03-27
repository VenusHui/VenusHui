// 58. 最后一个单词的长度
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int ans = 0, tmp = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == ' ') {
                while (s[i + 1] == ' ' && i + 1 < size) {
                    i++;
                }
                ans = tmp;
                tmp = 0;
            }
            else {
                tmp++;
            }
        }
        if (tmp != 0) {
            ans = tmp;
        }
        return ans;
    }
};