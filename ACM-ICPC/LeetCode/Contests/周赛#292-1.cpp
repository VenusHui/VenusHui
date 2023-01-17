// 6056. 字符串中最大的 3 位相同数字
class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int size = num.size();
        for (int i = 0; i < size - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                ans = max(ans, num.substr(i, 3));
            }
        }
        return ans;
    }
};