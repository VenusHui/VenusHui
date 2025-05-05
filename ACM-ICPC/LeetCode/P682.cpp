// 682. 棒球比赛
class Solution {
public:
  int convert(string num) {
    bool flag = true;
    if (num[0] == '-') {
      flag = false;
      num.erase(num.begin());
    }
    int ans = stoi(num);
    if (!flag) {
      ans *= -1;
    }
    return ans;
  }
  int calPoints(vector<string> &ops) {
    int size = ops.size();
    int ans = 0;
    int sco = 0;
    vector<int> res;
    for (int i = 0; i < size; i++) {
      if (ops[i] == "+") {
        int len = res.size();
        sco = res[len - 1] + res[len - 2];
        res.push_back(sco);
      } else if (ops[i] == "D") {
        int len = res.size();
        sco = 2 * res[len - 1];
        res.push_back(sco);
      } else if (ops[i] == "C") {
        res.pop_back();
      } else {
        sco = convert(ops[i]);
        res.push_back(sco);
      }
    }
    size = res.size();
    for (int i = 0; i < size; i++) {
      ans += res[i];
    }
    return ans;
  }
};