/**
 * @platform: AcWing
 * @problem: P790 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-09
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double n;
    cin >> n;
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double m = (l + r) / 2;
        if (pow(m, 3) <= n) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << l << '\n';

    return 0;
}
