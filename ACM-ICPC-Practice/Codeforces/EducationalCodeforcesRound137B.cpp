/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound137B 
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
        vector<int> ans(n);
        for (int i = 0; i < n / 2; i++) {
            ans[i] = i * 2 + 1;
            ans[n - 1 - i] = i * 2 + 2;
        }
        if (n % 2 != 0) {
            ans[n / 2] = n;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
