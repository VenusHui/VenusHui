// 2571. 将整数减少到零需要的最少操作数
class Solution {
public:
    int minOperations(int n) {
        int num = n;
        string s;
        while (num) {
            s += char('0' + num % 2);
            num /= 2;
        }
        int size = s.size(), tmp = 0, ans = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == '1') {
                tmp++;
            }
            else {
                if (tmp >= 2) {
                    s[i] = '1';
                    ans++, i--;
                    tmp = 0;
                }
                else {
                    ans += tmp;
                    tmp = 0;
                }
            }
        }
        return ans + (tmp >= 2 ? 2 : 1);
    }
};