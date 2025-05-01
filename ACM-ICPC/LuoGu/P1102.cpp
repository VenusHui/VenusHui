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
ll num[200005], ans;
int main() {
  ios_base::sync_with_stdio(false);
  int N, C;
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
  }
  sort(num, num + N);
  for (int i = 0; i < N; i++) {
    ans = ans + (upper_bound(num, num + N, num[i] - C) - num) -
          (lower_bound(num, num + N, num[i] - C) - num);
  }
  cout << ans << endl;

  return 0;
}