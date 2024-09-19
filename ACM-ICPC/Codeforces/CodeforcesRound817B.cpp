/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#817B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-12
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
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'G') {
                s1[i] = 'B';
            }
            if (s2[i] == 'G') {
                s2[i] = 'B';
            }
        }
        if (s1 == s2) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
