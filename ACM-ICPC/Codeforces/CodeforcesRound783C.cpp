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

// Codeforces Round #783 (Div. 2) C. Make it Increasing

// Contest Version

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> res(n);
  for (int i = 0; i < n; i++) {
    cin >> res[i];
  }
  ll ans = 1e18 + 1;
  for (int i = 0; i < n; i++) {
    ll tmp = 0, num = 0;
    // left
    num = 0;
    for (int j = i - 1; j >= 0; j--) {
      tmp += ((-1 * num) / res[j] + 1);
      num = -1 * ((-1 * num) / res[j] + 1) * res[j];
    }
    // right
    num = 0;
    for (int j = i + 1; j < n; j++) {
      tmp += (num / res[j] + 1);
      num = (num / res[j] + 1) * res[j];
    }
    ans = min(ans, tmp);
  }
  cout << ans << '\n';

  return 0;
}
