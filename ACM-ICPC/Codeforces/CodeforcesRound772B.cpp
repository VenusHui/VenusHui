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

// Codeforces Round #772 (Div. 2) B. Avoid Local Maximums
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
    int operNum = 0;
    for (int i = 1; i < n - 2; i++) {
      if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) {
        nums[i + 1] = max(nums[i], nums[i + 2]);
        operNum++;
      }
    }
    // 处理边界情况
    if (nums[n - 2] > nums[n - 1] && nums[n - 2] > nums[n - 3]) {
      nums[n - 2] = nums[n - 3];
      operNum++;
    }
    cout << operNum << '\n';
    for (int i = 0; i < n; i++)
      cout << nums[i] << " ";
    cout << '\n';
  }

  return 0;
}