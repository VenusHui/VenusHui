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

// Codeforces Round #787 (Div. 3) A. Food for Animals

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int suba = x - a, subb = y - b;
    if (suba <= 0 && subb <= 0) {
      cout << "YES" << '\n';
    } else {
      if (suba < 0) {
        suba = 0;
      }
      if (subb < 0) {
        subb = 0;
      }
      if (suba + subb <= c) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }

  return 0;
}