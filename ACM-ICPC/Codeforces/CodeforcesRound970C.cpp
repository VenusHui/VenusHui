/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#970C 
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
    auto calc = [&] (int num) {
        return (1 + num) * num / 2;
    };
    while (t--) {
        int l, r;
        cin >> l >> r;
        int num = r - l;
        int ll = 0, rr = 0x3f3f3f3f;
        while (ll < rr) {
            int m = (ll + rr + 1) >> 1;
            if (1LL * m * m + m <= 2 * num) {
                ll = m;
            }
            else {
                rr = m - 1;
            }
        }
        cout << ll + 1 << '\n';
    }

    return 0;
}
