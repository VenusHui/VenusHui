/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#797A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-06-07
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
        if (n % 3 == 0) {
            cout << n / 3 << " " << n / 3 + 1 << " " << n / 3 - 1 << '\n';
        }
        else if (n % 3 == 1) {
            cout << n / 3 << " " << n / 3 + 2 << " " << n / 3 - 1 << '\n';
        }
        else if (n % 3 == 2) {
            cout << n / 3 + 1 << " " << n / 3 + 2 << " " << n / 3 - 1 << '\n';
        }
    }

    return 0;
}
