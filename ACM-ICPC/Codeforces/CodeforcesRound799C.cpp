/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#799C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-09-14
 */
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
;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int maxn = 8;
  int t;
  cin >> t;
  while (t--) {
    pair<int, int> ans = make_pair(0, 0);
    vector<string> board(maxn);
    for (int i = 0; i < maxn; i++) {
      cin >> board[i];
    }
    int flag = 0;
    for (int i = 0; i < maxn; i++) {
      int num = 0;
      pair<int, int> tmp;
      for (int j = 0; j < maxn; j++) {
        if (board[i][j] == '#') {
          num++;
          tmp = make_pair(i + 1, j + 1);
        }
      }
      if (num == 2) {
        flag = 1;
      }
      if (num == 1 && flag == 1) {
        ans = tmp;
        break;
      }
    }
    cout << ans.first << " " << ans.second << '\n';
  }
  return 0;
}
