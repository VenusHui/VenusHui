/**
 * @platform: Nowcoder
 * @problem: 第十九届同济大学程序设计竞赛C 
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
    while (t--) {
        int n;
        cin >> n;
        vector<ll> h(n);
        ll minh = 1e9 + 1, sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            minh = min(minh, h[i]);
            sum += h[i];
        }
        sum -= n;
        if (n == 1 || n == 0) {
            cout << "YES" << '\n';
            continue;
        }
        ll l = 0, r = 7 * minh;
        while (l < r) {
            ll m = (l + r + 1) >> 1;
            if (m + m / 7 * (n - 1) <= sum) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        if ((l + 1) % 7 == 0 && l + l / 7 * (n - 1) == sum) {
            bool ans = true;
            for (int i = 0; i < n; i++) {
                if (h[i] < (l + 1) / 7) {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
        else {
            cout << "NO" << '\n';
        }        
    }

    return 0;
}
