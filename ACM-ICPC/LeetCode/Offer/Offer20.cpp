// 剑指 Offer 20. 表示数值的字符串
class Solution {
public:
    bool isNumber(string s) {
        auto checkNum = [&] (string num) {
            for (auto& e : num) {
                if (!(e >= '0' && e <= '9')) return false;
            }
            return true;
        };
        auto checkInteger = [&] (string num) {
            int size = num.size();
            if (!size) return false;
            if ((num[0] == '+' || num[0] == '-') && size <= 1) return false;
            for (int i = 0; i < size; i++) {
                if (!i && !(num[i] == '+' || num[i] == '-' || num[i] >= '0' && num[i] <= '9')) return false;
                if (i && !(num[i] >= '0' && num[i] <= '9')) return false;
            }
            return true;
        };
        auto checkDecimal = [&] (string num) {
            int size = num.size(), start = 0;
            if (size <= 1) return false;
            if (num[0] == '+' || num[0] == '-') start = 1;
            if (start == 1 && size <= 2) return false;
            for (int i = 0; i < size; i++) {
                if (num[i] == '.') {
                    if (i == 0) return checkNum(num.substr(i + 1));
                    if (i == size - 1) return checkNum(num.substr(start, i - start));
                    return checkNum(num.substr(start, i - start)) && checkNum(num.substr(i + 1));
                }
            }
            return false;
        };
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                return (checkInteger(s.substr(0, i)) || checkDecimal(s.substr(0, i))) && checkInteger(s.substr(i + 1));
            }
        }
        return checkInteger(s) || checkDecimal(s);
    }
};