/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound186A
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-12-30
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
        string s1 = "2025", s2 = "2026";
        bool flag1 = false, flag2 = false;
        for (int i = 0; i < n; i++) {
            if (s.substr(i, 4) == s1) {
                flag1 = true;
            }
            if (s.substr(i, 4) == s2) {
                flag2 = true;
            }
        }
        if (flag1 && !flag2) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
