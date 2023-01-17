/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound131A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-08
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
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        if (a1 + a2 + a3 + a4 == 0) {
            cout << "0" << '\n';
        }
        else if (a1 + a2 + a3 + a4 == 4) {
            cout << "2" << '\n';
        }
        else {
            cout << "1" << '\n';
        }
    }

    return 0;
}
