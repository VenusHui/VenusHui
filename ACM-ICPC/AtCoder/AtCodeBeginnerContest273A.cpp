/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest273A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-15
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    cout << ans << '\n';

    return 0;
}
