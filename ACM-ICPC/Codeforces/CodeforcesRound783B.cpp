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

// Codeforces Round #783 (Div. 2) B. Social Distance

// Contest Version

bool cmp(ll a, ll b) { return a > b; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
      cin >> res[i];
    }
    if (n > m) {
      cout << "NO" << '\n';
      continue;
    }
    sort(res.begin(), res.end(), cmp);
    ll cnt = 1;
    for (int i = 0; i < n - 1; i++) {
      cnt += res[i];
      cnt++;
    }
    if (m - cnt >= res[0] && m - cnt >= res[n - 1]) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
