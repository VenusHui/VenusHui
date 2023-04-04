/**
 * @platform: Nowcoder_Tencent
 * @problem: tencent_testB 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-26
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 26;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<bool>> vis(n);
    for (int i = 0; i < n; i++) {
        vis[i] = vector<bool>(a[i].size(), false);
    }
    vector<bool> status(maxn, false);
    vector<int> pos(n);
    vector<vector<int>> res;
    function<void(int)> dfs = [&] (int x) {
        if (x == n) {
            for (int i = 0; i < n; i++) {
                vis[i][pos[i]] = true;
            }
            res.push_back(pos);
            return;
        }
        int size = a[x].size();
        for (int i = 0; i < size; i++) {
            if (status[a[x][i] - 'a'] == false && vis[x][i] == false) {
                status[a[x][i] - 'a'] = true;
                pos[x] = i;
                dfs(x + 1);
                status[a[x][i] - 'a'] = false;
            }
        }
    };
    dfs(0);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        vis[i] = vector<bool>(a[i].size(), false);
    }
    for (auto& e : res) {
        for (int i = 0; i < n; i++) {
            vis[i][e[i]] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        int size = vis[i].size(), num = 0;
        for (int j = 0; j < size; j++) {
            if (vis[i][j]) num++;
        }
        ans = min(ans, num);
    }
    cout << ans << '\n';

    return 0;
}
