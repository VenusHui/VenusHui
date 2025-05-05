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

// Educational Codeforces Round 127 (Rated for Div. 2) A. String Building

// Contest Version

inline bool calc(string s) {
  int size = s.size();
  if (size == 1) {
    return false;
  } else {
    return true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s, tmp;
    cin >> s;
    int size = s.size();
    char ch = s[0];
    bool ans = true;
    for (int i = 0; i < size; i++) {
      if (s[i] == ch) {
        tmp += s[i];
      } else {
        if (!calc(tmp)) {
          ans = false;
          break;
        }
        tmp.clear();
        ch = s[i];
        tmp += s[i];
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
