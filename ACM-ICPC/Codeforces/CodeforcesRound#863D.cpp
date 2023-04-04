/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#863D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-04
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 45;
    int t;
    cin >> t;
    vector<ll> fib(maxn + 1, 1);
    for (int i = 2; i <= maxn; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        function<bool(int, ll, ll)> check = [&] (int l, ll ta, ll tb) {
            if (l == 1) return true;
            ll r = fib[l], c = fib[l + 1];
            bool ans = false;
            if (tb > r) ans |= check(l - 1, c - tb + 1, ta);
            else if (tb < c - r + 1) ans |= check(l - 1, c - r - tb + 1, ta);
            else return false;
            return ans;
        };
        if (check(n, x, y)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
