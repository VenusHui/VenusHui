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
typedef long long ll;
using namespace std;

// Educational Codeforces Round 124 (Div. 2) A. Equidistant Letters

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    const int maxNum = 1e9;
    bool flag = true;
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
      ans[i] = ans[i - 1] * 3 + 1;
      if (ans[i] < 0 || ans[i] > maxNum) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
      cout << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}