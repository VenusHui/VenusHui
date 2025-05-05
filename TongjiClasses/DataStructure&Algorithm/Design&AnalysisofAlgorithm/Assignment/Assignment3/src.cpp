/**
 * @platform: Class
 * @problem: Matrix Chain Multiplication
 * @version: Homework
 * @author: VenusHui
 * @date: 2022-06-03
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int matrixChainMultiplication(vector<int> &p) {
  // Calculate the minimum number of basic operations.
  int size = p.size();
  vector<vector<int>> dp(
      size,
      vector<int>(
          size)); // dp[i][j]表示从第i个矩阵乘到第j个矩阵所需要的最小乘法次数
  for (
      int len = 2; len < size;
      len++) { // 枚举子问题的长度（1个矩阵的情况永远为0，不用考虑，所以从2开始）
    for (int l = 1; l < size - len + 1; l++) {
      int r = l + len - 1; // 计算该长度下，每一个[l, r]区间
      dp[l][r] = 1 >> 30;  // 初始化为inf
      for (int k = l; k < r;
           k++) { // 在该[l, r]区间内枚举一个位置 k，计算将区间分为[l, k]和[k +
                  // 1, r]所需要的最小乘法次数
        int num = dp[l][k] + dp[k + 1][r] + p[l - 1] * p[k] * p[r];
        dp[l][r] = min(dp[l][r], num); // 更新dp[l][r]
      }
    }
  }
  return dp[1][size - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<int> p;
  function<void()> read = [&]() {
    string line;
    getline(cin, line, '\n'); // 由于Input中含有空格，这里一定是整行读取
    bool flag = false;
    string pInput;
    for (auto &it : line) {
      if (it == ']') // 在']'处结束，并且if语句的顺序不可调换
        break;
      if (flag && it != ' ')
        pInput += it;
      if (it == '[') // 从'['开始向数据部分添加数据
        flag = true;
    }
    stringstream ss;
    ss.str(pInput); // 创建数据流
    string item;
    char delim = ',';
    try {
      while (getline(ss, item, delim)) { // 每隔一个delim','进行一次处理
        p.push_back(stoi(item));         // 将string转换为int存入
      }
    } catch (std::invalid_argument &) { // 捕获stoi的非法转换异常
      cout << "Invalid argument" << endl;
    } catch (std::out_of_range &) { // 捕获stoi的越界转换异常
      cout << "Out of range" << endl;
    }
  };
  read();
  cout << matrixChainMultiplication(p) << '\n';

  return 0;
}
