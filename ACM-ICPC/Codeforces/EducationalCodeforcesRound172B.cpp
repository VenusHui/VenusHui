/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound172B
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-12-02
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
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
      cin >> c[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
      mp[c[i]]++;
    bool flag = true;
    int score = 0;
    for (auto &e : mp) {
      if (e.second == 1) {
        if (flag) {
          score += 2;
          flag = false;
        } else {
          flag = true;
        }
      } else {
        score++;
      }
    }
    cout << score << '\n';
  }

  return 0;
}
