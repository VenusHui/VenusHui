/**
 * @platform: Codefoeces
 * @problem: CodeforcesRound#792B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-19
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
        ll a, b, c;
        cin >> a >> b >> c;
        ll x, y, z;
        x = a + b + c;
        y = b + c;
        z = c;
        cout << x << " " << y << " " << z << '\n';
    }

    return 0;
}
