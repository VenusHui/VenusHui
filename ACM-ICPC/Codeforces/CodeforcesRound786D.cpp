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

// Codeforces Round #786 (Div. 3) D. A-B-C Sort

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
    for (int i = n - 1; i >= 1; i -= 2) {
      if (res[i - 1] > res[i]) {
        swap(res[i], res[i - 1]);
      }
    }
    bool ans = true;
    int tmp = res[0];
    for (int i = 1; i < n; i++) {
      if (tmp > res[i]) {
        ans = false;
        break;
      }
      tmp = res[i];
    }
    if (ans) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
