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

// Codeforces Round #787 (Div. 3) C. Detective Task

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int size = s.size();
    int start = 0, end = size - 1;
    for (int i = 0; i < size; i++) {
      if (s[i] == '1') {
        start = i;
      } else if (s[i] == '0') {
        break;
      }
    }
    for (int i = size - 1; i >= 0; i--) {
      if (s[i] == '0') {
        end = i;
      } else if (s[i] == '1') {
        break;
      }
    }
    cout << end - start + 1 << '\n';
  }

  return 0;
}
