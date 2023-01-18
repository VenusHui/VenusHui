// 2299. 强密码检验器 II
class Solution {
private:
    const int minn = 8;
    const string special_charactors = "!@#$%^&*()-+";
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if (n < minn) return false;
        bool lower_case = false, upper_case = false, num = false, special = false, same = true;
        for (int i = 0; i < n; i++) {
            if (password[i] >= 'a' && password[i] <= 'z') lower_case = true;
            if (password[i] >= 'A' && password[i] <= 'Z') upper_case = true;
            if (password[i] >= '0' && password[i] <= '9') num = true;
            if (special_charactors.find(password[i]) != string::npos) special = true;
            if (i && password[i] == password[i - 1]) same = false;
        }
        return lower_case && upper_case && num && special && same;
    }
};