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

// Codeforces Global Round 19 A.Sorting Parts
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    if (is_sorted(nums.begin(), nums.end()))
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }

  return 0;
}