/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#970B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-09-01
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
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
        string s;
        cin >> s;
        if (sqrt(n) * sqrt(n) != n) {
            cout << "No" << '\n';
            continue;
        }
        int l = sqrt(n);
        bool ans = true;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (i == 0 || j == 0 || i == l - 1 || j == l - 1) {
                    ans = ans && s[i * l + j] == '1';
                }
                else {
                    ans = ans && s[i * l + j] == '0';
                }
            }
        }
        if (ans) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}
