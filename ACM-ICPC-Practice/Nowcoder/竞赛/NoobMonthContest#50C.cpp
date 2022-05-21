/**
 * @platform: Nowcoder
 * @problem: NoobMonthContest#50C 
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
    int n;
    cin >> n;
    bool flagtwo = true, flagone = true;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
        if (res[i] > 1) {
            flagtwo = false;
        }
        if (res[i] > 0) {
            flagone = false;
        }
    }
    if (flagone) {
        cout << "0" << '\n';
        return 0;
    }
    if (flagtwo) {
        cout << "1" << '\n';
        return 0;
    }
    sort(res.begin(), res.end(), [&](int& a, int& b) {
        return a > b;
    });
    if (res[0] >= 2) {
        for (int i = 0; i < n; i++) {
            res[i] %= 2;
        }
    }
    flagtwo = true, flagone = true;
    for (int i = 0; i < n; i++) {
        if (res[i] > 1) {
            flagtwo = false;
        }
        if (res[i] > 0) {
            flagone = false;
        }
    }
    if (flagone) {
        cout << "1" << '\n';
        return 0;
    }
    if (flagtwo) {
        cout << "2" << '\n';
        return 0;
    }

    return 0;
}
