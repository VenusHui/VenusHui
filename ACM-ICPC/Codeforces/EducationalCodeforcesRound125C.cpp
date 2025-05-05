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

// Educational Codeforces Round 125 (Div. 2) C. Bracket Sequence Deletion

// 补题passed
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int operNum = 0, pos = 0;
    while (pos < n) {
      if (s[pos] == '(' && pos + 1 < n) {
        operNum++;
        pos += 2;
      } else {
        int len;
        bool flag = false;
        for (len = 2; len <= n - pos; len++) {
          flag = true;
          int l = pos, r = min(pos + len - 1, n - 1);
          while (l <= r) {
            if (s[l] == s[r]) {
              l++;
              r--;
            } else {
              flag = false;
              break;
            }
          }
          if (flag) {
            pos += len;
            operNum++;
            break;
          }
        }
        if (len >= n - pos - 1 && !flag) {
          break;
        }
      }
    }
    cout << operNum << " " << n - pos << '\n';
  }

  return 0;
}

// 不找规律的纯模拟 pertest passed but TLE at final test 10

// int length;
// int n, ans = 0;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         string str;
//         cin >> str;
//         ans = 0, length = n;
//         int ll = 0;
//         while (ll <= n)
//         {
//             int reflag = 0, paflag = 0;
//             // regular
//             stack<char> s;
//             int tmp = 0;
//             for (int i = ll; i < n; i++)
//             {
//                 if (str[i] == '(')
//                 {
//                     s.push('(');
//                     tmp++;
//                 }
//                 else
//                 {
//                     if (!s.empty())
//                     {
//                         s.pop();
//                         tmp++;
//                     }
//                     else
//                     {
//                         break;
//                     }
//                 }
//                 if (s.empty())
//                     break;
//             }
//             if (s.empty())
//                 reflag = tmp;

//             // palindrome
//             int len;
//             for (len = 2; len <= n - ll; len++)
//             {
//                 bool flag = true;
//                 int l = ll, r = ll + len - 1;
//                 while (l <= r)
//                 {
//                     if (str[l] == str[r])
//                     {
//                         l++;
//                         r--;
//                     }
//                     else
//                     {
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if (flag)
//                 {
//                     paflag = len;
//                     break;
//                 }
//             }

//             // all
//             if (reflag || paflag)
//             {
//                 if (reflag == 0)
//                 {
//                     ans++;
//                     ll += paflag;
//                     continue;
//                 }
//                 else if (paflag == 0)
//                 {
//                     ans++;
//                     ll += reflag;
//                     continue;
//                 }
//                 else if (reflag <= paflag)
//                 {
//                     ans++;
//                     ll += reflag;
//                     continue;
//                 }
//                 else
//                 {
//                     ans++;
//                     ll += paflag;
//                     continue;
//                 }
//             }
//             else
//             {
//                 break;
//             }
//         }

//         cout << ans << " " << n - ll << '\n';
//     }

//     return 0;
// }