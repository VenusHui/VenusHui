/**
 * @platform: Nowcoder
 * @problem: hedson_testA 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-05-26
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double w;
    string s;
    cin >> w >> s;
    w -= 1;
    int ans = 20;
    while (w > 0) {
        ans++;
        w -= 1;
    }
    if (s == "y") ans += 5;
    cout << ans << '\n';

    return 0;
}
