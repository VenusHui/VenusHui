// 2038. 如果相邻两个颜色均相同则删除当前颜色
class Solution {
public:
    bool winnerOfGame(string s) {
        int size = s.size();
        int tmp = -1;
        bool flagA = (s[0] == 'A');
        vector<int> a;
        vector<int> b;
        for (int i = 1; i < size; i++) {
            if (flagA && s[i] == 'A') {
                tmp++;
            }
            else if (!flagA && s[i] == 'B') {
                tmp++;
            }
            else {
                if (s[i] == 'A') {
                    if (tmp > 0) {
                        b.push_back(tmp);
                    }
                    flagA = true;
                    tmp = -1;
                }
                else {
                    if (tmp > 0) {
                        a.push_back(tmp);
                    }
                    flagA = false;
                    tmp = -1;
                }
            }
        }
        if (tmp > 0) {
            if (flagA)
                a.push_back(tmp);
            else
                b.push_back(tmp);
        }
        int ansA = 0, ansB = 0, sizeA = a.size(), sizeB = b.size();
        for (int i = 0; i < sizeA; i++)
            ansA += a[i];
        for (int i = 0; i < sizeB; i++)
            ansB += b[i];
        return ansA > ansB;
    }
};