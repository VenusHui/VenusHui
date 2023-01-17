/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound137C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-25
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
        string s;
        cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        int minn = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (minn > a[i]) {
                    ans += minn;
                    minn = a[i];
                }
                else {
                    ans += a[i];
                }
            }
            else {
                minn = a[i];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
