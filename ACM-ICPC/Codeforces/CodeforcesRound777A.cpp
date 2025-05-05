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
#include <unordered_set>
#include <vector>
typedef long long ll;
using namespace std;

// Codeforces Round #777 (Div. 2) A. Madoka and Math Dad

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cir = n / 3, mod = n % 3;
    if (mod == 0) {
      for (int i = 0; i < cir; i++)
        cout << "21";
      cout << endl;
    } else if (mod == 1) {
      for (int i = 0; i < cir; i++)
        cout << "12";
      cout << "1" << '\n';
    } else if (mod == 2) {
      for (int i = 0; i < cir; i++)
        cout << "21";
      cout << "2" << '\n';
    }
  }

  return 0;
}