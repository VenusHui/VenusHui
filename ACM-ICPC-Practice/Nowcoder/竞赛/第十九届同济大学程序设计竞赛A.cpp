/**
 * @platform: Nowcoder
 * @problem: 第十九届同济大学程序设计竞赛A 
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
    int t;
    cin >> t;
    function<ll(ll, ll)> gcd = [&] (ll x, ll y) {
        return y ? gcd(y, x % y) : x;
    };
    while (t--) {
        ll n, a;
        cin >> n >> a;
        ll top = (n - a) * (n - a) * (n - a), btm = n * n * n - a * a * a;
        ll fac = gcd(top, btm);
        while (fac != 1) {
            top /= fac;
            btm /= fac;
            fac = gcd(top, btm);
        }
        cout << top << "/" << btm << '\n';
    }

    return 0;
}
