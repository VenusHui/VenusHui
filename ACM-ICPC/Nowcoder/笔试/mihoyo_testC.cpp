/**
 * @platform: Nowcoder_mihoyo
 * @problem: mihoyo_testC 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-19
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> status;
    int ans = 0;
    function<void(int)> dfs = [&] (int x) {
        if (x == n) {
            ans = (ans + 1) % mod;
            return;
        }
        dfs(x + 1);
        bool flag = true;
        for (auto& e : status) {
            if (max(e, a[x]) % min(e, a[x]) != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            status.push_back(a[x]);
            dfs(x + 1);
            status.pop_back();
        }
    };
    dfs(0);
    cout << ans - 1 - n << '\n';

    return 0;
}
