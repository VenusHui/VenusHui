/**
 * @platform: Meituan
 * @problem: meituan_testD 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-01
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    for (int i = 0; i < n; i++) cin >> z[i];
    cin >> m;
    while (m--) {
        int q, ans = 0x3f3f3f3f;
        cin >> q;
        q--;
        int vol = 0;
        for (int i = q; i >= 0; i--) {
            vol += (x[i] - y[i]);
            ans = min(ans, vol * z[i]);
        }
        cout << ans << " ";
    }
    cout << '\n';

    return 0;
}
