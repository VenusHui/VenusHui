/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#834A.cpp
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s, str;
    cin >> s;
    for (int i = 0; i < 50; i++) {
      str += "Yes";
    }
    if (str.find(s) != string::npos) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

  return 0;
}
