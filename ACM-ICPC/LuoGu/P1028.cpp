#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int dp[1000 + 5];
int main() {
  int num;
  cin >> num;
  dp[1] = 1;
  for (int i = 2; i <= num; i++) {
    dp[i]++;
    for (int j = i / 2; j != 0; j--) {
      dp[i] += dp[j];
    }
  }
  cout << dp[num] << endl;
  return 0;
}

// 暴力递归会超时，用动态规划解决