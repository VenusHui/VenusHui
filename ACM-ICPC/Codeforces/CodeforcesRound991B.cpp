/**
 * @platform: Codeforces
 * @problem: CodeforcesRound991B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-12-05
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += 1LL * a[i];
        if (sum % n != 0) {
            cout << "NO" << '\n';
            continue;
        }
        int avg = static_cast<int>(sum / n);
        for (int i = 0; i < n - 2; i++) {
            if (a[i] < avg) {
                int diff = avg - a[i];
                a[i] += diff;
                a[i + 2] -= diff;
            }
            else if (a[i] > avg) {
                int diff = a[i] - avg;
                a[i] -= diff;
                a[i + 2] += diff;
            }
        }
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != avg) {
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

    return 0;
}
