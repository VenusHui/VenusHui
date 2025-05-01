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

// Educational Codeforces Round 125(Div.2) B. XY Sequence

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, b;
    ll x, y;
    cin >> n >> b >> x >> y;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (a[i - 1] + x <= b) {
        a[i] = a[i - 1] + x;
      } else {
        a[i] = a[i - 1] - y;
      }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
      ans += a[i];
    }
    cout << ans << '\n';
  }

  return 0;
}
