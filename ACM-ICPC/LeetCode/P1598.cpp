// 1598. 文件夹操作日志搜集器
class Solution {
public:
  int minOperations(vector<string> &logs) {
    int size = logs.size();
    int ans = 0;
    for (int i = 0; i < size; i++) {
      if (logs[i] == "../") {
        ans = max(ans - 1, 0);
      } else if (logs[i] == "./") {
        ans = ans;
      } else {
        ans++;
      }
    }
    return ans;
  }
};