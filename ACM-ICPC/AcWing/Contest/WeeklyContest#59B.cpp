/**
 * @platform: AcWing
 * @problem: WeeklyContest#59B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-09
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll maxn = 1e5;
    vector<bool> prime(maxn + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; pow(i, 2) < maxn; i++) {
        if (prime[i]) {
            for (int j = pow(i, 2); j <= maxn; j += i) {
                prime[j] = false;
            }
        }
    }
    vector<ll> res;
    for (int i = 0; i <= maxn; i++) {
        if (prime[i]) {
            res.push_back(static_cast<ll>(i));
        }
    }
    ll n, num = 0;
    cin >> n;
    function<ll(ll)> calc = [&] (ll x) {
        for (auto& it : res) {
            if (x % it == 0) {
                return it;
            }
        }
        return x;
    };
    while (n != 0) {
        if (n % 2 == 0) {
            num += n / 2;
            break;
        }
        n -= calc(n);
        num++;
    }
    cout << num << '\n';

    return 0;
}
