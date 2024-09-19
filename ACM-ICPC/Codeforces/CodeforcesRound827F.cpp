/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#827F 
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
    const int maxn = 26;
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        vector<ll> s(maxn), t(maxn);
        while (q--) {
            ll d, k;
            cin >> d >> k;
            string x;
            cin >> x;
            if (d == 1) {
                for (auto ch : x) {
                    s[ch - 'a'] += k;
                }
            }
            else {
                for (auto ch : x) {
                    t[ch - 'a'] += k;
                }
            }
            bool flag = true, saflag = true;
            for (int i = 1; i < maxn; i++) {
                if (t[i] != 0) {
                    flag = false;
                }
                if (s[i] != 0) {
                    saflag = false;
                }
            }
            if (!flag) {
                cout << "YES" << '\n';
                continue;
            }
            if (saflag) {
                if (s[0] < t[0]) {
                    cout << "YES" << '\n';
                }
                else {
                    cout << "NO" << '\n';
                }
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}
