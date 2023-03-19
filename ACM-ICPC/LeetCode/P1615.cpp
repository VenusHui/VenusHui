// 1615. 最大网络秩
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for (auto& e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = adj[i].size() + adj[j].size();
                function<bool()> check = [&] () {
                    for (auto& e : adj[i]) {
                        if (e == j) return false;
                    }
                    return true;
                };
                if (!check()) tmp--;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};