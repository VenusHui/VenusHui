// 6055. 转化时间需要的最少操作数
class Solution {
public:
    int convertTime(string current, string correct) {
        int ch = (current[0] - '0') * 10 + (current[1] - '0') * 1;
        int cm = (current[3] - '0') * 10 + (current[4] - '0') * 1;
        int ah = (correct[0] - '0') * 10 + (correct[1] - '0') * 1;
        int am = (correct[3] - '0') * 10 + (correct[4] - '0') * 1;
        int ans = 0;
        int adh = 0, adm = 0;
        if (ch > ah || ch == ah && cm > am) {
            adh = (24 - (ch - ah - 1));
            adm = (60 + am) - cm;
        }
        else {
            adh = ah - ch;
            if (cm > am) {
                adm = (60 + am) - cm;
                adh--;
            }
            else {
                adm = am - cm;
            }
        }
        ans += adh;
        while (adm) {
            if (adm >= 15) {
                adm -= 15;
            }
            else if (adm >= 5) {
                adm -= 5;
            }
            else if (adm >= 1) {
                adm -= 1;
            }
            ans++;
        }
        return ans;
    }