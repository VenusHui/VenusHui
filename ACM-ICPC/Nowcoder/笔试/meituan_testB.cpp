/**
 * @platform: Meituan
 * @problem: meituan_testB 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-01
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i + 1] - a[i];
    }
    cout << ans << '\n';

    return 0;
}
