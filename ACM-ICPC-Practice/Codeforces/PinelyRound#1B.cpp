/**
 * @platform: Codeforces
 * @problem: PinelyRound#1B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-20
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool flag = false;
        int size = a.size();
        for (int i = 0; i < size; i++) {
            if (a[(i + size - 1) % size] != a[(i + size + 1) % size]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << size << '\n';
        }
        else {
            cout << size / 2 + 1 << '\n';
        }
    }

    return 0;
}
