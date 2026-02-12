/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1065C1
 * @version: Contest Version
 * @author: VenusHui
 * @date:2025-11-21
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
        for (int i = 0; i < n; i++) cin >> a[i]; // Ajisai
        for (int i = 0; i < n; i++) cin >> b[i]; // Mai
        bool aflag = false, bflag = false;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != b[i]) {
                if ((i + 1) % 2) aflag = true;
                else bflag = true;
                break;
            }
        }
        int anum = 0, bnum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) anum++;
            if (b[i] == 1) bnum++;
        }
        if ((anum % 2 + bnum % 2) % 2 == 0) {
            cout << "Tie" << '\n';
        }
        else if (anum % 2 + bnum % 2 == 1) {
            if (aflag) cout << "Ajisai" << '\n';
            if (bflag) cout << "Mai" << '\n';
            if (!aflag && !bflag) cout << "Tie" << '\n';
        }
    }
    return 0;
}
