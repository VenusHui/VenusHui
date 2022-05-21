/**
 * @platform: Nowcoder
 * @problem: 武汉理工大学第三届程序设计竞赛D 
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
        cout << 3 * n + n / 3 * n << " " << n / 3 * 10 << '\n';
    }

    return 0;
}
