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

// A. Suffix Array - 1
int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  s.push_back('$');
  int size = s.size();
  vector<int> p(size); // the position in the string s
  vector<int> c(size); // the equivalence class of each suffix, the subscript
                       // represent the position in the string s;
  {
    // k = 0;
    vector<pair<char, int>> a(size);
    for (int i = 0; i < size; i++)
      a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for (int i = 0; i < size; i++)
      p[i] = a[i].second;
    c[p[0]] = 0; // initialize
    for (int i = 1; i < size; i++) {
      if (a[i].first == a[i - 1].first) {
        c[p[i]] = c[p[i - 1]];
      } else {
        c[p[i]] = c[p[i - 1]] + 1;
      }
    }
  }

  int k = 0;
  while ((1 << k) < size) {
    // from k to k + 1
    vector<pair<pair<int, int>, int>> a(size);
    for (int i = 0; i < size; i++)
      a[i] = {{c[i], c[(i + (1 << k)) % size]}, i}; // circlize the string
    sort(a.begin(), a.end());
    for (int i = 0; i < size; i++)
      p[i] = a[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < size; i++) {
      if (a[i].first == a[i - 1].first) {
        c[p[i]] = c[p[i - 1]];
      } else {
        c[p[i]] = c[p[i - 1]] + 1;
      }
    }
    k++;
  }

  for (int i = 0; i < size; i++)
    cout << p[i] << " ";
  cout << "\n";
  return 0;
}