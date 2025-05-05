class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> g(n);
        for (auto & e : edges) {
            g[e[1]].push_back(make_pair(e[0], e[2]));
        }
        function<int(vector<vector<pair<int, int>>>&, int)> dijsktra = [&] (vector<vector<pair<int, int>>> edge, int s) {
            vector<int> dist(n, 0x3f3f3f3f);
            dist[s] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            q.push(make_pair(dist[s], s));
            while(!q.empty()) {
                pair<int, int> cnt = q.top();
                q.pop();
                for (auto& e : g[cnt.second]) {
                    int new_dist = max(cnt.first, e.second);
                    if (new_dist < dist[e.first]) {
                        dist[e.first] = new_dist;
                        q.push(make_pair(new_dist, e.first));
                    }
                }
            }
            int ans = -0x3f3f3f3f;
            for (int i = 0; i < n; i++) ans = max(ans, dist[i]);
            if (ans == 0x3f3f3f3f) return -1;
            return ans;
        };
        return dijsktra(g, 0);
    }
};