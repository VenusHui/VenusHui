/**
 * @platform: Nowcoder
 * @problem: NoobMonthContest#50B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-21
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int ans = 0;
    while (n > 0) {
        if (n - n / 2 > x) {
            n /= 2;
        }
        else {
            n -= x;
        }
        ans++;
    }
    cout << ans << '\n';

    return 0;
}
