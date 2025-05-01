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

// Codeforces Round #787 (Div. 3) D. Vertical Paths

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, root;
    cin >> n;
    vector<int> res(n + 1);
    vector<bool> leaf(n + 1, true), visit(n + 1, false);
    for (int i = 1; i <= n; i++) {
      cin >> res[i];
      leaf[res[i]] = false;
      if (i == res[i]) {
        root = i;
      }
    }
    if (n == 1) {
      cout << 1 << '\n' << 1 << '\n' << 1 << '\n' << '\n';
      continue;
    }
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++) {
      if (leaf[i]) {
        vector<int> tmp;
        visit[i] = true;
        tmp.push_back(i);
        int pos = res[i];
        while (!visit[pos]) {
          visit[pos] = true;
          tmp.push_back(pos);
          if (pos == root) {
            break;
          }
          pos = res[pos];
        }
        reverse(tmp.begin(), tmp.end());
        ans.push_back(tmp);
      }
    }
    int size = ans.size();
    cout << size << '\n';
    for (int i = 0; i < size; i++) {
      int asize = ans[i].size();
      cout << asize << '\n';
      for (int j = 0; j < asize; j++) {
        cout << ans[i][j] << " ";
      }
      cout << '\n';
    }
    cout << '\n';
  }

  return 0;
}
