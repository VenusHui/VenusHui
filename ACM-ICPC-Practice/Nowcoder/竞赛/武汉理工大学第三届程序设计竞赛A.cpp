/**
 * @platform: Nowcoder
 * @problem: 武汉理工大学第三届程序设计竞赛A 
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
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n < 9 || n == 10) {
            cout << "0" << '\n';
            continue;
        }
        if (n % 2 == 0) {
            cout << 2 * ((n - 3) / 2 - 2) << '\n';
        }
        else {
            cout << 2 * ((n - 2) / 2 - 1) << '\n';
        }
    }

    return 0;
}
