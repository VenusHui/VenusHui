/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1065C2
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
    const int maxn = 32;

    function<int(int, vector<int>&, vector<int>&)> calc = [&] (int n, vector<int>& a, vector<int>& b) {
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
            return 0;
        }
        else if (anum % 2 + bnum % 2 == 1) {
            if (aflag) return 1;
            if (bflag) return -1;
            if (!aflag && !bflag) return 0;
        }
        return 0;
    };

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<vector<int>> ad(n, vector<int>(maxn, 0)), bd(n, vector<int>(maxn, 0));
        for (int i = 0; i < n; i++) {
            int index = maxn - 1, tmp = a[i];
            while (tmp) {
                if (tmp % 2) ad[i][index] = 1;
                tmp /= 2;
                index--;
            }
        }
        for (int i = 0; i < n; i++) {
            int index = maxn - 1, tmp = b[i];
            while (tmp) {
                if (tmp % 2) bd[i][index] = 1;
                tmp /= 2;
                index--;
            }
        }
        int ans = 0;
        for (int i = 0; i < maxn; i++) {
            vector<int> at(n), bt(n);
            for (int j = 0; j < n; j++) {
                at[j] = ad[j][i];
                bt[j] = bd[j][i];
            }
            ans = calc(n, at, bt);
            if (ans != 0) break;
        }
        if (ans == 1) {
            cout << "Ajisai" << '\n';
        }
        else if (ans == 0) {
            cout << "Tie" << '\n';
        }
        else if (ans == -1) {
            cout << "Mai" << '\n';
        }
    }
    return 0;
}
