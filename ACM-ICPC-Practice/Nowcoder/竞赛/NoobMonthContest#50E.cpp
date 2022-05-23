/**
 * @platform: Nowcoder
 * @problem: NoobMonthContest#50E 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2022-05-23
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a <= c) {
        cout << n / a << '\n';
    }
    else {
        int cnt = min((n - c) / b, (n - b) / c);
        cout << cnt + (n - cnt * c) / a << '\n';
    }

    return 0;
}
