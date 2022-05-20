// 150. 逆波兰表达式求值
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int size = tokens.size();
        for (int i = 0; i < size; i++)
        {
            if (tokens[i][0] >= '0' && tokens[i][0] <= '9' || tokens[i].size() > 1) {
                int tmp = stoi(tokens[i]);
                nums.push(tmp);
            }
            else
            {
                int r = nums.top();
                nums.pop();
                int l = nums.top();
                nums.pop();
                int res;
                switch (tokens[i][0]) {
                    case '+':
                        res = l + r;
                        break;
                    case '-':
                        res = l - r;
                        break;
                    case '*':
                        res = l * r;
                        break;
                    case '/' :
                        res = l / r;
                        break; 
                }
                nums.push(res);
            }
        }
        return nums.top();
    }
};