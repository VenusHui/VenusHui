/***********************************
 *  Codeforces Round #790 (Div. 4)
 *  F. Longest Strike
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
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> res[i];
      mp[res[i]]++;
    }
    vector<int> ans;
    for (auto &it : mp) {
      if (it.second >= k) {
        ans.push_back(it.first);
      }
    }
    int size = ans.size();
    if (size == 0) {
      cout << "-1" << '\n';
      continue;
    }
    ans.push_back(-1);
    bool flag = false;
    int r = -1, l = -1;
    vector<pair<int, int>> last;
    for (int i = 0; i < size; i++) {
      if (!flag) {
        l = r = ans[i];
        flag = true;
      }
      if (flag && ans[i] + 1 == ans[i + 1]) {
        r = ans[i + 1];
      } else if (ans[i] + 1 != ans[i + 1]) {
        last.push_back(make_pair(l, r));
        flag = false;
      }
    }
    sort(last.begin(), last.end(), [&](pair<int, int> &a, pair<int, int> &b) {
      return a.second - a.first > b.second - b.first;
    });
    cout << last[0].first << " " << last[0].second << '\n';
  }

  return 0;
}
