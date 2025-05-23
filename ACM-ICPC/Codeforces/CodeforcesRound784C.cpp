#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
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

// Codeforces Round #784 (Div. 4) C

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      cin >> res[i];
    }
    bool ans = true;
    int flag = res[0] % 2;
    for (int i = 0; i < n; i++) {
      if (res[i] % 2 != flag) {
        ans = false;
        break;
      }
    }
    if (ans) {
      cout << "YES" << '\n';
      continue;
    }
    for (int i = 0; i < n; i += 2) {
      res[i] += 1;
    }
    ans = true;
    flag = res[0] % 2;
    for (int i = 0; i < n; i++) {
      if (res[i] % 2 != flag) {
        ans = false;
        break;
      }
    }
    if (ans) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
