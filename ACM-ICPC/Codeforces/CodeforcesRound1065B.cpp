/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1065B
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-11-21
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
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
        for (int i = 1; i < n - 1; i++) {
            if (a[i] == -1) a[i] = 0;
        }
        if (a[0] == -1 && a[n - 1] == -1) {
            a[0] = 0, a[n - 1] = 0;
        }
        else if (a[0] == -1) a[0] = a[n - 1];
        else if (a[n - 1] == -1) a[n - 1] = a[0];
        cout << abs(a[0] - a[n - 1]) << '\n';
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
