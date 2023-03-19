/**
 * @platform: Nowcoder-PDD
 * @problem: pdd_testB 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    cin >> t >> n;
    vector<int> a(n);
    while (t--) {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            ans++;
            if (a[i] == 1) {
                a[i]--;
                if (i < n - 1) a[i + 1]--;
            }
            else {
                a[i] = 0;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
