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
        if (n == 4 && s[0] == '1' && s[1] == '1' && s[2] == '1' && s[3] == '1') {
            cout << "Yes" << '\n';
            continue;
        }
        int l = sqrt(n);
        if (s[l + 1] == '0') {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}
