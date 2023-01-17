/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest258A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-02
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k;
    cin >> k;
    if (k < 10) {
        cout << "21:0" << k << '\n';
    }
    else if (k < 60) {
        cout << "21:" << k << '\n';
    }
    else if (k < 70) {
        cout << "22:0" << k - 60 << '\n';
    }
    else {
        cout << "22:" << k - 60 << '\n';
    }

    return 0;
}
