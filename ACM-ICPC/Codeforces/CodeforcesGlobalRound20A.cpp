/***********************************
 *  Codeforces Global Round 20
 *  A. Log Chopping
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
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      ans += num - 1;
    }
    if (ans % 2 == 0) {
      cout << "maomao90" << '\n';
    } else {
      cout << "errorgorn" << '\n';
    }
  }

  return 0;
}
