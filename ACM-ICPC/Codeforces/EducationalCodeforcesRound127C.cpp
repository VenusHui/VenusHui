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

// Educational Codeforces Round 127 (Rated for Div. 2) C. Dolce Vita

// Contest Version

int n, x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vector<ll> res(n), pre(n);
    for (int i = 0; i < n; i++) {
      cin >> res[i];
    }
    sort(res.begin(), res.end());
    partial_sum(res.begin(), res.end(), pre.begin());
    ll ans = 0, day = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (x - pre[i] - (i + 1) * day >= 0) {
        ll tmp = x - pre[i] - (i + 1) * day;
        ll num = tmp / (i + 1);
        ans = ans + (i + 1) * (num + 1);
        day += (num + 1);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
