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

// Codeforces Round #786 (Div. 3) A. Number Transformation

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int x, y, a = 0, b = 0;
    cin >> x >> y;
    if (x > y || y % x != 0) {
      cout << a << " " << b << '\n';
      continue;
    }
    int tmp = y / x;
    cout << 1 << " " << tmp << '\n';
  }

  return 0;
}
