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

// Educational Codeforces Round 125(Div. 2) A.Integer Moves

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      cout << "0" << '\n';
      continue;
    }
    int dis = sqrt(x * x + y * y);
    if (dis * dis == x * x + y * y) {
      cout << "1" << '\n';
    } else {
      cout << "2" << '\n';
    }
  }

  return 0;
}
