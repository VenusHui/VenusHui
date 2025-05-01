// 282. 给表达式添加运算符
// 完全跟着官方题解的思路走的
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    int length = num.size();
    vector<string> ans;
    function<void(string &, int, long, long)> backTrack =
        [&](string &expr, int index, long res, long pre) {
          if (index == length) {
            if (res == target) {
              ans.push_back(expr);
            }
            return;
          }
          int signSize = expr.size();
          if (index != 0) {
            expr.push_back('x'); // 占位，便于后续添加符号
          }
          long val = 0;
          for (int i = index; i < length && (i == index || num[index] != '0');
               i++) {
            val = 10 * val + num[i] - '0';
            expr.push_back(num[i]);
            if (index == 0) {
              backTrack(expr, i + 1, val, val);
            } else {
              expr[signSize] = '+';
              backTrack(expr, i + 1, res + val, val);
              expr[signSize] = '-';
              backTrack(expr, i + 1, res - val, -val);
              expr[signSize] = '*';
              backTrack(expr, i + 1, res - pre + pre * val, pre * val);
            }
          }
          expr.resize(signSize);
        };
    string expr;
    backTrack(expr, 0, 0, 0);
    return ans;
  }
};