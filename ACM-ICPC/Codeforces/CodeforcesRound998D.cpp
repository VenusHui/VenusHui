/**
 * @platform: Codeforces
 * @problem: CodeforcesRound998D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-19
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
        for (int i = 0; i < n - 1; i++) {
            int diff = min(a[i], a[i + 1]);
            a[i] -= diff;
            a[i + 1] -= diff;
        }
        bool ans = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
