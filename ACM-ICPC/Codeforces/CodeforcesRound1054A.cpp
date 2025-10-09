/**
 * @platform: Codeforces
 * @problem: CodeforcesRound1054A 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2025-10-01
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
        int num = 0, operation = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) num++;
            if (a[i] == 0) operation++;
        }
        if (num % 2) operation += 2;
        cout << operation << '\n';
    }

    return 0;
}
