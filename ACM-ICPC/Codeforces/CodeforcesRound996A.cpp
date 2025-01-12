/**
 * @platform: Codeforces
 * @problem: CodeforcesRound996A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-01-12
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
        int n, a, b;
        cin >> n >> a >> b;
        int diff = abs(a - b);
        if (diff % 2 == 0) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
