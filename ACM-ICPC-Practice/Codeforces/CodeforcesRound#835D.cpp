/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#835D 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-11-21
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
        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i - 1] > a[i]) {
                bool flag = false;
                for (int j = i; j < n; j++) {
                    if (j == n - 1 || a[j + 1] > a[i]) {
                        flag = true;
                        i = j;
                        break;
                    }
                    else if (a[j + 1] < a[i]) {
                        i = j;
                        break;
                    }
                }
                if (flag) {
                    ans++;
                }
            }
        }
        if (ans == 1) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}
