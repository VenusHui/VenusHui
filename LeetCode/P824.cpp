// 824. 山羊拉丁文
class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans, tmp;
        int size = sentence.size();
        int pos = 0;
        for (int i = 0; i < size; i++) {
            if (sentence[i] != ' ') {
                tmp += sentence[i];
            }
            if (sentence[i] == ' ' || i == size - 1) {
                pos++;
            if (tmp[0] == 'a' || tmp[0] == 'e' || tmp[0] == 'i' || tmp[0] == 'o' || tmp[0]== 'u' || tmp[0] == 'A' || tmp[0] == 'E' || tmp[0] == 'I' || tmp[0] == 'O' || tmp[0]== 'U') {
                 tmp += "ma";   
                }
                else {
                    tmp += tmp[0];
                    tmp.erase(tmp.begin());
                    tmp += "ma";
                }
                for (int j = 0; j < pos; j++) {
                    tmp += "a";
                }
                if (i != size - 1) {
                    tmp += " ";
                }
                ans += tmp;
                tmp.clear();
            }
        }
        return ans;
    }
};