/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#836D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-26
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
    const int maxn = 6e5;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << "3 1" << '\n';
            continue;
        }
        ll total = 1LL * maxn * maxn;
        vector<ll> res(n);
        ll avg = total / n;
        res[0] = avg - 3e5, res[n - 1] = avg + 3e5;
        total -= 2 * avg;
        avg = total / (n - 2);
        int num = static_cast<int>(total % (n - 2));
        for (int i = 1; i < n - 1 - num; i++) {
            res[i] = avg;
        }
        for (int i = max(0, n - 1 - num); i < n - 1; i++) {
            res[i] = avg + 1;
        }
        if (n % 2 == 0) {
            for (int i = 1; i < n - 1; i++) {
                if (i < n / 2) {
                    res[i] -= i;
                }
                else {
                    res[i] += i - n / 2 + 1;
                }
            }
        }
        else {
            for (int i = 1; i < n - 1; i++) {
                if (i == n / 2) {
                    continue;
                }
                if (i < n / 2) {
                    res[i] -= i;
                }
                else {
                    res[i] += i - n / 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
