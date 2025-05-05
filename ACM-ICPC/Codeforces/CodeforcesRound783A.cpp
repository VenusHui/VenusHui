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

// Codeforces Round #783 (Div. 2) A. Direction Change

// Contest Version

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if ((n == 1 || m == 1) && n * m > 2) {
      cout << "-1" << '\n';
      continue;
    }
    ll square = min(n, m), rest = max(m, n) - min(m, n);
    ll ans = 2 * (square - 1) + 4 * (rest / 2) + (rest % 2);
    cout << ans << '\n';
  }

  return 0;
}
