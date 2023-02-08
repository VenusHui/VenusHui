// 1129. 颜色交替的最短路径
// Tutorial Version
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));
        for (auto& e : redEdges) adj[0][e[0]].push_back(e[1]);
        for (auto& e : blueEdges) adj[1][e[0]].push_back(e[1]);
        vector<vector<int>> dist(2, vector<int>(n, 0x3f3f3f3f));
        dist[0][0] = 0, dist[1][0] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        q.push(make_pair(0, 1));
        while (!q.empty()) {
            pair<int, int> cnt = q.front();
            q.pop();
            for (auto& e : adj[1 - cnt.second][cnt.first]) {
                if (dist[1 - cnt.second][e] == 0x3f3f3f3f) {
                    dist[1 - cnt.second][e] = dist[cnt.second][cnt.first] + 1;
                    q.push(make_pair(e, 1 - cnt.second));
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = min(dist[0][i], dist[1][i]);
            if (ans[i] == 0x3f3f3f3f) ans[i] = -1;
        }
        return ans;
    }
};