/**
 * @platform: Codeforeces
 * @problem: CodeforcesRound#834E 
 * @version: Conetest Version
 * @author: VenusHui
 * @date: 2022-11-19
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
        ll n, h;
        cin >> n >> h;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int flag = 0, ans = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            if (a[i] < h) {
                h += a[i] / 2;
                ans++;
                cout << a[i] << " " << h << " " << ans << '\n';
            }
            else {
                if (flag == 0 || flag == 1) {
                    h *= 2;
                    flag++;
                }
                else if (flag == 2) {
                    h *= 3;
                    flag++;
                }
                else {
                    break;
                }
                i--;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
