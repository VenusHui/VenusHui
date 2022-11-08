// 1678. 设计 Goal 解析器
class Solution {
public:
    string interpret(string command) {
        int size = command.size();
        string ans;
        for (int i = 0; i < size; i++) {
            if (command[i] == 'G') {
                ans += "G";
            }
            else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ans += 'o';
                    i++;
                }
                else {
                    ans += "al";
                    i += 3;
                }
            }
        }
        return ans;
    }
};