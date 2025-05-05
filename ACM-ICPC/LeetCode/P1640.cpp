// 1640. 能否连接形成数组
class Solution {
public:
  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    int asize = arr.size(), psize = pieces.size();
    for (int i = 0; i < psize; i++) {
      int size = pieces[i].size();
      vector<int>::iterator it = find(arr.begin(), arr.end(), pieces[i][0]);
      bool flag = true;
      if (it != arr.end()) {
        for (int j = 0; j < size; j++, it++) {
          if (it == arr.end() || *it != pieces[i][j]) {
            flag = false;
            break;
          }
        }
      } else {
        flag = false;
      }
      if (!flag) {
        return false;
      }
    }
    return true;
  }
};