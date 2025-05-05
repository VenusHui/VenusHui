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

// Codeforces Round #784 (Div. 4) G. Fall Down

inline void calc(vector<vector<char>> &res, int tmp, int row, int col) {
  if (tmp == 0) {
    return;
  }
  for (int i = row; i > row - tmp; i--) {
    res[i][col] = '*';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> res(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> res[i][j];
      }
    }
    for (int j = 0; j < m; j++) {
      int tmp = 0;
      for (int i = 0; i < n; i++) {
        if (res[i][j] == '*') {
          res[i][j] = '.';
          tmp++;
        } else if (res[i][j] == 'o') {
          calc(res, tmp, i - 1, j);
          tmp = 0;
        }
      }
      calc(res, tmp, n - 1, j);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << res[i][j];
      }
      cout << '\n';
    }
  }

  return 0;
}
