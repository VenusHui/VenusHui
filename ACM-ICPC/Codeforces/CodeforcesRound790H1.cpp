/***********************************
 *  Codeforces Round #790 (Div. 4)
 *  H1. Maximum Crossings (Easy Version)
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Date: 2022-05-11
 ***********************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> res(n);
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      res[i] = make_pair(i + 1, num);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n && i != j; j++) {
        if (res[j].first >= res[i].first && res[j].second <= res[i].second ||
            res[j].first <= res[i].first && res[j].second >= res[i].second) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
