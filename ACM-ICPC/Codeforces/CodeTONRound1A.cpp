#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

// CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!) A - Good Pairs

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> res(n);
    for (int i = 0; i < n; i++) {
      cin >> res[i].first;
      res[i].second = i + 1;
    }
    sort(res.begin(), res.end());
    cout << res[0].second << " " << res[n - 1].second << '\n';
  }

  return 0;
}
