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

// Educational Codeforces Round 126 (Rated for Div. 2) A. Array Balancing

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
      ll cnt = abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
      ll cvt = abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]);
      if (cnt > cvt) {
        swap(a[i], b[i]);
      }
      ans += min(cnt, cvt);
    }
    cout << ans << '\n';
  }

  return 0;
}