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

// Codeforces Round #774 (Div. 2) A. Square Counting

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll n, s;
    cin >> n >> s;
    cout << s / (n * n) << '\n';
  }
  return 0;
}