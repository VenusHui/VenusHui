/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1074A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2026-01-18
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
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}
