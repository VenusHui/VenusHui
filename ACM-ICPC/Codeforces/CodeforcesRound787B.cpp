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

// Codeforces Round #787 (Div. 3) B. Make It Increasing

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
      cin >> res[i];
    }
    bool flag = true;
    ll ans = 0;
    for (int i = n - 1; i > 0; i--) {
      if (res[i] <= res[i - 1]) {
        if (res[i - 1] == 0) {
          flag = false;
          break;
        }
        res[i - 1] /= 2;
        ans++;
        i++;
      }
    }
    if (flag) {
      cout << ans << '\n';
    } else {
      cout << "-1" << '\n';
    }
  }

  return 0;
}
