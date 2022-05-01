// 第一题 移除指定数字得到的最大结果
class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans;
        int size = number.size();
        for (int i = 0; i < size; i++) {
            if (number[i] == digit) {
                string tmp = number;
                tmp.erase(tmp.begin() + i);
                ans = max(tmp, ans);
            }
        }
        return ans;
    }
};