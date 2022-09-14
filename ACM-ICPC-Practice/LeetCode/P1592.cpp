// 1592. 重新排列单词间的空格
class Solution {
public:
    string reorderSpaces(string text) {
        int size = text.size();
        string ans;
        int num = 0, wnum = 0;
        bool flag = true;
        for (int i = 0; i < size; i++) {
            if (text[i] == ' ') {
                num++;
                flag = true;
            }
            else {
                if (flag) {
                    wnum++;
                    flag = false;
                }
            }
        }
        int per = 0, t = wnum;
        if (wnum != 1) {        
            per = num / (wnum - 1);
        }
        flag = true;
        for (int i = 0; i < size; i++) {
            if (text[i] != ' ') {
                ans += text[i];
                flag = true;
            }
            if (flag && text[i] == ' ' && ans.size() != 0 && --t > 0) {
                ans += string(per, ' ');
                flag = false;
            }
        }
        ans += string(num - per * (wnum - 1), ' ');
        return ans;
    }
};