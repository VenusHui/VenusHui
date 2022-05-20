// 6070. 计算字符串的数字和
class Solution {
public:
    string digitSum(string s, int k) {
        string ans = s;
        while (ans.size() > k) {
            int pos = 0;
            string tmp;
            while (pos < ans.size()) {
                int num = 0, end = pos + k;
                for (int i = pos; i < end && pos < ans.size(); i++, pos++) {
                    num += (ans[i] - '0');
                }
                tmp += to_string(num);
            }
            ans = tmp;
        }
        return ans;
    }
};