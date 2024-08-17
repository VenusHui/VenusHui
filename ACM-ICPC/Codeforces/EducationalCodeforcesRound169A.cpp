/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound169A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2024-08-17
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
        if (n == 1 || n == 2 && abs(a[0] - a[1]) > 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
