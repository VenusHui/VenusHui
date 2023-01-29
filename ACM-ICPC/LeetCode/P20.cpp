// 20. 有效的括号
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto& e : s) {
            if (e == '(' || e == '{' || e == '[') stk.push(e);
            else if (e == ')' && !stk.empty() && stk.top() == '(') stk.pop();
            else if (e == ']' && !stk.empty() && stk.top() == '[') stk.pop();
            else if (e == '}' && !stk.empty() && stk.top() == '{') stk.pop();
            else return false;
        }
        return stk.empty();
    }
};