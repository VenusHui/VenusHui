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

// Codeforces Round #784 (Div. 4) B

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
    sort(res.begin(), res.end());
    int num = 1;
    for (int i = 1; i < n; i++) {
      if (res[i] == res[i - 1]) {
        num++;
      } else {
        num = 1;
      }
      if (num >= 3) {
        cout << res[i] << '\n';
        break;
      }
    }
    if (num < 3) {
      cout << "-1" << '\n';
    }
  }

  return 0;
}
