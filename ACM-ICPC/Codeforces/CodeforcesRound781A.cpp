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

// Codeforces Round #781 (Div. 2) A. GCD vs LCM

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      if (n % 4 == 0) {
        cout << n / 4 << " " << n / 4 << " " << n / 4 << " " << n / 4 << '\n';
      } else {
        cout << (n - 2) / 2 - 1 << " " << (n - 2) / 2 + 1 << " " << 1 << " "
             << 1 << '\n';
      }
    } else {
      cout << (n - 2) / 2 << " " << (n - 2) / 2 + 1 << " " << 1 << " " << 1
           << '\n';
    }
  }

  return 0;
}
