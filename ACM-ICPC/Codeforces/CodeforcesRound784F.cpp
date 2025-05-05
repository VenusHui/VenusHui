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

// Codeforces Round #784 (Div. 4) F

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    vector<int> a(n), b(n);
    partial_sum(w.begin(), w.end(), a.begin());
    b[0] = w[n - 1];
    int pos = n - 2;
    for (int i = 1; i < n; i++) {
      b[i] = b[i - 1] + w[pos];
      pos--;
    }
    int ans = 0;
    int asize = 0, bsize = 0;
    while (asize + bsize + 2 <= n) {
      if (a[asize] < b[bsize]) {
        asize++;
      } else if (a[asize] > b[bsize]) {
        bsize++;
      } else {
        ans = max(ans, asize + bsize + 2);
        asize++;
        bsize++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
