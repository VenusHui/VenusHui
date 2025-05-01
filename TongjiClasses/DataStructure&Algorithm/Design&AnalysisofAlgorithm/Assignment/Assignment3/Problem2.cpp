/**
 * @platform: Class
 * @problem: Problem2
 * @version: Homework
 * @author: VenusHui
 * @date: 2022-06-02
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<int> stocks;
  function<void()> read = [&]() {
    string line;
    cin >> line;
    bool flag = false;
    string stockInput;
    for (auto &it : line) {
      if (it == ']') // 在']'处结束，并且if语句的顺序不可调换
        break;
      if (flag)
        stockInput += it;
      if (it == '[') // 从'['开始向数据部分添加数据
        flag = true;
    }
    stringstream ss;
    ss.str(stockInput); // 创建数据流
    string item;
    char delim = ',';
    try {
      while (getline(ss, item, delim)) { // 每隔一个delim','进行一次处理
        stocks.push_back(stoi(item));    // 将string转换为int存入
      }
    } catch (std::invalid_argument &) { // 捕获stoi的非法转换异常
      cout << "Invalid argument" << endl;
    } catch (std::out_of_range &) { // 捕获stoi的越界转换异常
      cout << "Out of range" << endl;
    }
  };
  read();
  int size = stocks.size();
  vector<vector<int>> dp(size + 1, vector<int>(2));
  dp[0][0] = 0;
  dp[1][0] = 0, dp[1][1] = -1 * stocks[0];
  for (int i = 2; i <= size; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + stocks[i - 1]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - stocks[i - 1]);
  }
  cout << dp[size][0] << '\n';

  return 0;
}
