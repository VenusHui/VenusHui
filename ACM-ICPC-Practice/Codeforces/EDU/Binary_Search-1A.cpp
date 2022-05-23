/**
 * @platform: Codeforces
 * @problem: Binary_Search-1 
 * @version: EDU
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
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (res[m] <= num) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        if (res[l] == num) {
            cout << "YES" << '\n'; 
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
