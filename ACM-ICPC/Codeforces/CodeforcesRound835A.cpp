/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#835A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-21
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
        int a, b, c;
        cin >>  a >> b >> c;
        cout << a + b + c - min(min(a, b), c) - max(max(a, b), c) << '\n';
    }

    return 0;
}
