/**
 * @platform: Nowcoder_mihoyo
 * @problem: mihoyo_testA 
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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) cin >> grid[i];
    function<void(int, int)> calc = [&] (int x, int y) {
        vis[x][y] = true;
        for (auto& e : dir) {
            pair<int, int> nxt = {x + e.first, y + e.second};
            if (nxt.first >= 0 && nxt.first < n && nxt.second >= 0 && nxt.second < m && grid[x][y] == grid[nxt.first][nxt.second]) {
                if (!vis[nxt.first][nxt.second]) calc(nxt.first, nxt.second);
            }
        }
    };
    int anum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            anum++;
            calc(i, j);
        }
    }
    for (auto& e : grid) {
        for (auto& c : e) if (c == 'G') c = 'B';
    }
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    int bnum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            bnum++;
            calc(i, j);
        }
    }
    cout << anum - bnum << '\n';

    return 0;
}
