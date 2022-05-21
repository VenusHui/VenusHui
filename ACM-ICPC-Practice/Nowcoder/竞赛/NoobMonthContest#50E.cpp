/**
 * @platform: Nowcoder
 * @problem: NoobMonthContest#50E 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-21
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a <= c) {
        cout << n / a << '\n';
        return 0;
    }
    ll l = 0, r = n / b;
    while (l < r) {
        ll m = (l + r + 1) >> 1;
        if ((n - m * c) / a * a + (m - 1) * c <= m * b) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    cout << l << '\n';
    cout << (n - l * c) / a + l << '\n';

    return 0;
}
