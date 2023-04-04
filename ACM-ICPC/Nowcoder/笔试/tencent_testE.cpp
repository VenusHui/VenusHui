/**
 * @platform: Nowcoder_Tencent
 * @problem: tencent_testE 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-26
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int mod = 1e9 + 7;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<bool>> res;
    vector<bool> status(n, false);
    function<void(int)> dfs = [&] (int x) {
        if (x == n) {
            res.push_back(status);
            return;
        }
        dfs(x + 1);
        status[x] = true;
        dfs(x + 1);
        status[x] = false;
    };
    dfs(0);
    int ans = 0;
    for (auto& e : res) {
        int size = e.size();
        int tmp = 0x3f3f3f3f;
        for (int i = 0; i < size; i++) {
            if (e[i]) {
                if (tmp == 0x3f3f3f3f) tmp = a[i];
                else tmp = gcd(tmp, a[i]);
            }
        }
        if (tmp == k) ans++;
    }
    cout << ans << '\n';

    return 0;
}
