// 1021. 删除最外层的括号
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int size = s.size();
        vector<bool> flag(size, false);
        stack<char> stk;
        int l = 0, r = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                stk.push('(');
            }
            else {
                stk.pop();
                if (stk.size() == 0) {
                    flag[l] = true;
                    flag[i] = true;
                    l = r = i + 1;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (!flag[i]) {
                ans += s[i];
            }
        }
        return ans;
    }
};