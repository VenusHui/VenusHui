/***********************************
 *  Educational Codeforces Round 128 (Rated for Div. 2)
 *  A. Minimums and Maximums
 *  Writer: VenusHui on Clion
 *  Version: Tutorial Version
 *  Date: 2022-05-13
***********************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        pair<int, int> a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        pair<int, int> l = min(a, b), r = max(a, b);
        if (l.second >= r.first) {
            cout << r.first << '\n';
        }
        else {
            cout << l.first + r.first << '\n';
        }
    }

    return 0;
}
