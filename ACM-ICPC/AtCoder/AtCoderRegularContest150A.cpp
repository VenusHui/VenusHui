/**
 * @platform: AtCoder
 * @problem: AtCoderRegularContest150A
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-09
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s.insert(s.begin(), '0');
    s.insert(s.end(), '0');
    n += 2;
    int ans = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        pos.push_back(i);
      }
    }
    int size = pos.size();
    for (int i = 0; i < size - 1; i++) {
      if (pos[i + 1] - pos[i] - 1 == k) {
        ans++;
      } else if (pos[i + 1] - pos[i] - 1 == k + 1) {
        if (!(s[pos[i + 1] - 1] == s[pos[i] + 1])) {
          ans++;
        } else if (s[pos[i] + 1] == '?') {
          ans += 2;
        }
      } else if (pos[i + 1] - pos[i] - 1 >= k + 2) {
        for (int j = pos[i] + 1; j <= pos[i + 1] - 1; j++) {
          if (s[j] == '?' || s[j] == '1' && s[j - 1] == '?') {
            if (j + k <= pos[i + 1] - 1) {
              if (s[j + k + 1] != '1') {
                ans++;
              }
            }
          }
        }
      }
    }
    if (ans == 1) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

  return 0;
}

//                 if (s[pos[i] + 1] == '1' && s[pos[i + 1] - 1] == '1') {
//                     continue;
//                 }
//                 else if (s[pos[i] + 1] == '?' && s[pos[i + 1] - 1] == '?') {
//                     ans += 2;
//                 }
//                 else if (s[pos[i] + 1] == '1') {
//                     bool tflag = false;
//                     int tmp = 0;
//                     for (int j = pos[i] + 1; j <= pos[i + 1] - 1; j++) {
//                         if (s[j] == '1') {
//                             tmp++;
//                         }
//                         else {
//                             if (tmp < k) {
//                                 tmp++;
//                             }
//                             else if (tmp == k) {
//                                 ans++;
//                                 tflag = true;
//                             }
//                             else {
//                                 break;
//                             }
//                         }
//                     }
//                     if (!tflag && tmp == k) {
//                         ans++;
//                     }
//                 }
//                 else if (s[pos[i + 1] - 1] == '1') {
//                     bool tflag = false;
//                     int tmp = 0;
//                     for (int j = pos[i + 1] - 1; j >= pos[i] + 1; j--) {
//                         if (s[j] == '1') {
//                             tmp++;
//                         }
//                         else {
//                             if (tmp < k) {
//                                 tmp++;
//                             }
//                             else if (tmp == k) {
//                                 ans++;
//                                 tflag = true;
//                             }
//                             else {
//                                 break;
//                             }
//                         }
//                     }
//                     if (!tflag && tmp == k) {
//                         ans++;
//                     }
//                 }