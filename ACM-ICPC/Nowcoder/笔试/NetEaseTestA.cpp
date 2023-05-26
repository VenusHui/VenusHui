class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param map int整型vector<vector<>> 代表地图的二维数组
     * @param a_x int整型 小 A 出生点的 x 坐标
     * @param a_y int整型 小 A 出生点的 y 坐标
     * @param b_x int整型 小 B 出生点的 x 坐标
     * @param b_y int整型 小 B 出生点的 y 坐标
     * @return int整型
     */
    int getEstTime(vector<vector<int> >& map, int a_x, int a_y, int b_x, int b_y) {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = map.size(), m = map[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0x3f3f3f3f));
        pair<int, int> s = make_pair(a_x, a_y), e = make_pair(b_x, b_y);
        function<void(pair<int, int>, int)> dfs = [&] (pair<int, int> p, int stp) {
            if (!(p.first >= 0 && p.first < n && p.second >= 0 && p.second < m)) return;
            if (map[p.first][p.second] == 0) return;
            if (vis[p.first][p.second] <= stp) return;
            vis[p.first][p.second] = stp;
            for (auto& dir : dirs) {
                dfs(make_pair(p.first + dir.first, p.second + dir.second), stp + 1);
            }
        };
        dfs(s, 0);
        return vis[e.first][e.second] == 0x3f3f3f3f ? -1 : (vis[e.first][e.second] + 1) / 2;
    }
};