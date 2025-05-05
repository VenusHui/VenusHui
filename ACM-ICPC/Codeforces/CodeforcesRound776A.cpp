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

// Codeforces Round #776 (Div. 3) A. Deletions of Two Adjacent Letters

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    char c;
    string s;
    cin >> s >> c;
    bool flag = false;
    int size = s.size();
    for (int i = 0; i < size; i++) {
      if (s[i] == c && i % 2 == 0) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }

  return 0;
}
