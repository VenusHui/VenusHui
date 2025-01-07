class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n);
        for (auto& e : dislikes) {
            g[e[0] - 1].push_back(e[1] - 1);
            g[e[1] - 1].push_back(e[0] - 1);
        }
        vector<int> disjoint_set(n);
        for (int i = 0; i < n; i++) disjoint_set[i] = i;
        function<int(int)> find = [&] (int x) {
            if (disjoint_set[x] != x) disjoint_set[x] = find(disjoint_set[x]);
            return disjoint_set[x];
        };
        function<void(int, int)> set_union = [&] (int a, int b) {
            disjoint_set[find(a)] = find(b);
        };
        function<bool(int, int)> is_union = [&] (int a, int b) {
            return find(a) == find(b);
        };
        for (int i = 0; i < n; i++) {
            int size = g[i].size();
            for (int j = 0; j < size; j++) {
                if (is_union(i, g[i][j])) return false;
                if (j) set_union(g[i][j - 1], g[i][j]);
            }
        }
        return true;
    }
};