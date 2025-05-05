/***********************************
 *  Codeforces Round #785 (Div. 2)
 *  C. Palindrome Basis
 *  Writer: VenusHui
 *  Version: Tutorial Version
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

inline int reverse(int n) {
  int ans = 0;
  while (n) {
    ans = ans * 10 + n % 10;
    n /= 10;
  }
  return ans;
}

inline bool palindrome(int num) { return reverse(num) == num; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int mod = 1e9 + 7;
  const int maxn = 4e4 + 1;
  vector<int> res;
  res.push_back(0);
  for (int i = 1; i <= maxn; i++) {
    if (palindrome(i)) {
      res.push_back(i);
    }
  }
  int size = res.size();
  vector<vector<int>> dp(maxn, vector<int>(size, 0));
  for (int j = 0; j < size; j++) {
    dp[0][j] = 1;
  }
  for (int i = 1; i < maxn; i++) {
    for (int j = 1; j < size; j++) {
      if (i - res[j] >= 0) {
        dp[i][j] = (dp[i][j - 1] + dp[i - res[j]][j]) % mod;
      } else {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << dp[n][size - 1] << '\n';
  }

  return 0;
}
