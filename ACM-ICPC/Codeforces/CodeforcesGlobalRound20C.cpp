/***********************************
 *  Codeforces Global Round 20
 *  C. Unequal Array
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Date: 2022-05-10
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
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      cin >> res[i];
    }
    int l = -1, r = -1;
    for (int i = 0; i < n - 1; i++) {
      if (res[i] == res[i + 1]) {
        if (l == -1) {
          l = i;
        }
        r = i;
      }
    }
    if (l == r) {
      cout << "0" << '\n';
    } else {
      cout << max(r - l - 1, 1) << '\n';
    }
  }

  return 0;
}
