/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#836B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-25
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 33;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            for (int i = 0; i < n; i++) {
                cout << "1" << ' ';
            }
            cout << '\n';
        }
        else {
            if (n == 2) {
                cout << "1 3" << '\n';
                continue;
            }
            int num = (2 * n - 4) / (n - 2);
            for (int i = 0; i < n - 2; i++) {
                cout << num << ' ';
            }
            cout << "3 1" << '\n';
        }
    }

    return 0;
}
