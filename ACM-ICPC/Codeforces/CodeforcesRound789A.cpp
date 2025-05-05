/*********************************
 *  Codeforces Round #789 (Div. 2) A
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Date: 2022-05-08
 *********************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, num = 0;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      cin >> res[i];
      if (res[i] != 0) {
        num++;
      }
    }
    sort(res.begin(), res.end());
    int flag = 2;
    for (int i = 0; i < n - 1; i++) {
      if (res[i] == 0) {
        flag = min(flag, 0);
      }
      if (res[i] == res[i + 1]) {
        flag = min(flag, 1);
      }
    }
    if (flag == 0) {
      cout << num << '\n';
    } else if (flag == 1) {
      cout << n << '\n';
    } else {
      cout << n + 1 << '\n';
    }
  }

  return 0;
}
