/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest273B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-15
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll x, k;
    cin >> x >> k;
    for (int i = 0; i < k; i++) {
        ll pos = x % static_cast<ll>(pow(10, i + 1));
        ll num = x / static_cast<ll>(pow(10, i + 1));
        x = num * static_cast<ll>(pow(10, i + 1));
        if (pos / static_cast<ll>(pow(10, i)) >= 5) {
            x += static_cast<ll>(pow(10, i + 1));
        }
    }
    cout << x << '\n';

    return 0;
}
