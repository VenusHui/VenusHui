/*********************************
 *  Codeforces Round #789 (Div. 2) B1
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Date: 2022-05-08
 *********************************/
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
    string s;
    cin >> s;
    s += "$";
    int tmp = 1;
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (s[i] == s[i + 1]) {
        tmp++;
      } else {
        res.push_back(tmp);
        tmp = 1;
      }
    }
    int size = res.size(), ans = 0;
    for (int i = 0; i < size - 1; i++) {
      if (res[i] % 2 != 0) {
        res[i]++;
        res[i + 1]++;
        ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
