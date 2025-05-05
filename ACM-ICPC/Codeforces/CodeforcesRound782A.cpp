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
#include <unordered_map>
#include <vector>
typedef long long ll;
using namespace std;

// Codeforces Round #782 (Div. 2) A. Red Versus Blue

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, r, b;
    cin >> n >> r >> b;
    string ans;
    int size;
    int num1 = 0, num2 = 0;
    if (r % (b + 1) == 0) {
      size = r / (b + 1);
      num2 = b + 1;
    } else {
      size = r / (b + 1) + 1;
      num2 = r % (b + 1);
      num1 = b + 1 - num2;
    }
    for (int i = 0; i < num2; i++) {
      for (int j = 0; j < size; j++) {
        ans += "R";
      }
      if (ans.size() < n)
        ans += "B";
    }
    for (int i = 0; i < num1; i++) {
      for (int j = 0; j < size - 1; j++) {
        ans += "R";
      }
      if (ans.size() < n)
        ans += "B";
    }
    cout << ans << '\n';
  }

  return 0;
}
