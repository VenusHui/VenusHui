/**
 * @platform: Meituan
 * @problem: meituan_testA 
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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    for (int i = 0; i < 2 * m ; i++) {
        int pos;
        string oper;
        if (i % 2 == 0) {
            cin >> pos;
        }
        else {
            cin >> oper;
            double ans = sum;
            if (oper == "-") {
                ans -= 2 * a[pos];
            }
            else if (oper == "*") {
                ans = ans - a[pos] - a[pos - 1] + a[pos] * a[pos - 1];
            }
            else if (oper == "/") {
                ans = ans - a[pos] - a[pos - 1] + 1.0 * a[pos - 1] / a[pos];
            }
            cout << setiosflags(ios::fixed) << setprecision(1) << ans << " ";
        }
    }
    cout << '\n';

    return 0;
}
