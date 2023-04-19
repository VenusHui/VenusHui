// 1042. 不邻接植花
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n);
        vector<vector<int>> adj(n);
        for (auto& e : paths) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        for (int i = 0; i < n; i++) {
            vector<bool> color(5, false);
            for (auto& e : adj[i]) color[ans[e]] = true;
            for (int j = 1; j < 5; j++) if (color[j] == false) ans[i] = j;
        }
        return ans;
    }
};