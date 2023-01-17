// 2285. 道路的最大总重要性
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<vector<int>> res(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            res[i][0] = i + 1;
        }
        int size = roads.size();
        for (int i = 0; i < size; i++) {
            res[roads[i][0]][1]++;
            res[roads[i][1]][1]++;
        }
        sort(res.begin(), res.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (int i = 0; i < n; i++) {
            res[i][2] = i + 1;
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < size; i++) {
            ans += res[roads[i][0]][2] + res[roads[i][1]][2];
        }
        return ans;
    }
};