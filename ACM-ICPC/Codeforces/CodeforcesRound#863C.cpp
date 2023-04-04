/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#863C 
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n - 1; i++) cin >> b[i];
        a[0] = b[0];
        for (int i = 0; i < n - 1; i++) {
            a[i + 1] = min(max(a[i], b[i]), b[i + 1]);
        }
        a[n - 1] = b[n - 2];
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << '\n';
    }

    return 0;
}
