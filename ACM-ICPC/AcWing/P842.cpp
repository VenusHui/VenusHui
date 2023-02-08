/**
 * @platform: AcWing
 * @problem: P842 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-31
 */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> status(n + 1);
    vector<int> tmp(n);
    function<void(int)> dfs = [&] (int x) {
        if (x == n) {
            for (auto& e : tmp) cout << e << " ";
            cout << '\n';
        }
        for (int i = 1; i <= n; i++) {
            if (!status[i]) {
                tmp[x] = i;
                status[i] = true;
                dfs(x + 1);
                status[i] = false;
            }
        }
    };
    dfs(0);

    return 0;
}
