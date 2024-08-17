/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound169B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-08-17
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
        int la, lb, ra, rb;
        cin >> la >> ra >> lb >> rb;
        int lc, ld, rc, rd;
        if (la <= lb) {
            lc = la, rc = ra;
            ld = lb, rd = rb;
        }
        else {
            lc = lb, rc = rb;
            ld = la, rd = ra;
        }
        int ans;
        if (rc < ld) {
            ans = 1;
        }
        else if (rd <= rc) {
            ans = rd - ld;
            if (lc != ld) ans++;
            if (rc != rd) ans++;
        }
        else if (rd > rc) {
            ans = rc - ld;
            if (lc != ld) ans++;
            if (rc != rd) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
