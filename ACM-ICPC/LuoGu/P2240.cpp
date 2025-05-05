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

int main() {
  double ans = 0;
  int N, T, w, v;
  cin >> N >> T;
  vector<pair<double, int>> value;
  for (int i = 0; i < N; i++) {
    cin >> w >> v;
    value.push_back(
        make_pair(static_cast<double>(v) / static_cast<double>(w), w));
  }
  sort(value.begin(), value.end());
  for (int i = N - 1; i >= 0; i--) {
    if (T - value[i].second <= 0) {
      ans += value[i].first * T;
      break;
    }
    T -= value[i].second;
    ans += value[i].first * value[i].second;
  }
  cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;

  return 0;
}

// 最简单的贪心解决