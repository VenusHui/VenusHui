/**
 * @platform: Nowcoder
 * @problem: NoobMonthContest#50C 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2022-05-23
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
    function<int(int, int)> gcd = [&] (int a, int b) {
        return b ? gcd(b, a % b) : a;
    };
    int flag = 0;
    bool zflag = true, oflag = true;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
        flag = gcd(flag, res[i]);
        if (zflag && res[i] != 0) {
            zflag = false;
        }
        if (oflag && res[i] > 1) {
            oflag = false;
        }
    }
    if (zflag) {
        cout << "0" << '\n';
    }
    else if (oflag || flag > 1) {
        cout << "1" << '\n';
    }
    else {
        cout << "2" << '\n';
    }

    return 0;
}
