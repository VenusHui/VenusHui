// 2303. 计算应缴税款总额
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int size = brackets.size();
        bool flag = false;
        for (int i = size - 1; i > 0; i--) {
            if (!flag && brackets[i - 1][0] <= income) {
                ans += 1.0 * (income - brackets[i - 1][0]) * brackets[i][1] / 100;
                flag = true;
            }
            else if (flag) {
                ans += 1.0 * (brackets[i][0] - brackets[i - 1][0]) * brackets[i][1] / 100;
            }
        }
        if (income >= brackets[0][0]) {
            ans += 1.0 * brackets[0][0] * brackets[0][1] / 100;
        }
        else {
            ans += 1.0 * income * brackets[0][1] / 100;
        }
        return ans;
    }
};