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

// Codeforces Round #784 (Div. 4) D

bool calc(string tmp) {
  int size = tmp.size();
  if (size == 0) {
    return true;
  }
  char flag = tmp[0];
  for (int i = 0; i < size; i++) {
    if (tmp[i] != flag) {
      return true;
    }
  }
  return false;
}

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
    bool ans = true;
    string tmp;
    for (int i = 0; i < n; i++) {
      if (s[i] != 'W') {
        tmp += s[i];
      } else {
        if (calc(tmp) == false) {
          ans = false;
          break;
        }
        tmp.clear();
      }
    }
    if (!tmp.empty() && ans) {
      ans = calc(tmp);
    }
    if (ans) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
