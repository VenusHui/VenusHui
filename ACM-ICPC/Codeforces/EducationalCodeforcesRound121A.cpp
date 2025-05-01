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

// Educational Codeforces Round 121 (Div. 2) A. Equidistant Letters

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int size = s.size();
    vector<int> res(26);
    for (int i = 0; i < size; i++)
      res[s[i] - 'a']++;
    string ans;
    for (int i = 0; i < 26; i++) {
      if (res[i] == 2)
        ans += char(i + 'a');
    }
    for (int i = 0; i < 26; i++) {
      if (res[i] == 2)
        ans += char(i + 'a');
    }
    for (int i = 0; i < 26; i++) {
      if (res[i] == 1)
        ans += char(i + 'a');
    }
    cout << ans << '\n';
  }
  return 0;
}