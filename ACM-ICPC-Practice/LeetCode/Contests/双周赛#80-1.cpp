// 2299. 强密码检验器 II
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int size = password.size();
        if (size < 8) {
            return false;
        }
        bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = true;
        for (int i = 0; i < size; i++) {
            if (password[i] >= 'a' && password[i] <= 'z') {
                flag1 = true;
            }            
            if (password[i] >= 'A' && password[i] <= 'Z') {
                flag2 = true;
            }
            if (password[i] >= '0' && password[i] <= '9') {
                flag3 = true;
            }
            if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '+' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-') {
                flag4 = true;
            }
            if (i < size - 1 && password[i] == password[i + 1]) {
                flag5 = false;
                break;
            }
        }
        return flag1 && flag2 && flag3 && flag4 && flag5;
    }
};
