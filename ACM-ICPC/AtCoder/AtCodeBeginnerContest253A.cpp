/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest253A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-05-28
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    int d = max(a, c);
    int e = min(a, c);
    if (b >= e && b <= d) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }

    return 0;
}
