/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest272A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-08
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    cout << ans << '\n';

    return 0;
}
