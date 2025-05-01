/**
 * @platform: Codeforces
 * @problem: CodeforcseRound991C
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-12-05
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
  map<int, int> mp;
  mp[1] = 10;
  mp[2] = 2;
  mp[3] = 12;
  mp[4] = 4;
  mp[5] = 14;
  mp[6] = 6;
  mp[7] = 16;
  mp[8] = 8;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (s[i] - '0');
    }
    if (sum % 9 == 0) {
      cout << "YES" << '\n';
      continue;
    }
    int diff = mp[9 - sum % 9];
    int tsize = 0, ssize = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        tsize++;
      } else if (s[i] == '3') {
        ssize++;
      }
    }
    if (tsize == 0) {
      if (6 * ssize >= diff) {
        if (diff % 6 == 0) {
          cout << "YES" << '\n';
        } else {
          cout << "NO" << '\n';
        }
      } else {
        cout << "NO" << '\n';
      }
    } else if (tsize == 1) {
      if (2 * tsize + 6 * ssize >= diff) {
        bool ans = false;
        for (int i = 0; i <= ssize; i++) {
          if (6 * i == diff || 2 + 6 * i == diff) {
            ans = true;
            break;
          }
        }
        if (ans) {
          cout << "YES" << '\n';
        } else {
          cout << "NO" << '\n';
        }
      } else {
        cout << "NO" << '\n';
      }
    } else {
      if (2 * tsize + 6 * ssize >= diff) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }

  return 0;
}
