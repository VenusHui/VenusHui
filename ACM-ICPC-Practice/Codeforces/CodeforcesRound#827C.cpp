/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#827C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-13
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 8;
    int t;
    cin >> t;
    while (t--) {
        string x;
        getline(cin, x);
        vector<string> s(maxn);
        for (int i = 0; i < maxn; i++) {
            cin >> s[i];
        }
        char ans = '.';
        for (int i = 0; i < maxn; i++) {
            if (s[i][0] == '.') {
                continue;
            }
            char tmp = 'R';
            bool flag = true;
            for (int j = 0; j < maxn; j++) {
                if (s[i][j] != tmp) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = tmp;
            }
        }
        for (int i = 0; i < maxn; i++) {
            if (s[0][i] == '.') {
                continue;
            }
            char tmp = 'B';
            bool flag = true;
            for (int j = 0; j < maxn; j++) {
                if (s[j][i] != tmp) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = tmp;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
