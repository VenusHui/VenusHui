/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound137A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-25
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << 6 * (10 - n) * (10 - n - 1) / 2 << '\n';
    }

    return 0;
}
