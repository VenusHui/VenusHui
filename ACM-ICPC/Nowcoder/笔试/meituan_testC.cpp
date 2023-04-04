/**
 * @platform: Meituan
 * @problem: meituan_testC 
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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    vector<int> op(m), a(m), b(m);
    for (int i = 0; i < m; i++) cin >> op[i];
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < m; i++) {
        if (op[i] == 0) {
            arr[a[i]] = b[i];
        }
        else {
            int ans = 0;
            for (int j = a[i]; j <= b[i]; j++) {
                ans += arr[j];
            }
            cout << ans << " ";
        }
    }
    cout << '\n';

    return 0;
}
