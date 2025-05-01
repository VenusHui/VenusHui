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

// Codeforces Round #774 (Div. 2) B. Quality vs Quantity
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
    sort(nums.begin(), nums.end());
    ll sumRed = 0, sumBlue = nums[0];
    int ll = 1, rr = n - 1;
    while (ll < rr) {
      if (sumRed > sumBlue)
        break;
      sumRed += nums[rr--];
      sumBlue += nums[ll++];
    }
    if (sumRed > sumBlue)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}