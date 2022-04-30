// LCP 56. 信物传送
class Solution {
    int sol;
    int row, col, mins;
public:
    void dfs(vector<string>& matrix, vector<vector<int>>& v, pair<int, int> cnt, pair<int, int> end, int ans) {
        if (cnt.first >= row || cnt.second >= col || cnt.first < 0 || cnt.second < 0) {
            return;
        }
        if (ans >= mins || ans >= v[cnt.first][cnt.second]) {
            return;
        }
        if (cnt == end) {
            sol = min(sol, ans);
            mins = sol;
            return;
        }
        v[cnt.first][cnt.second] = min(ans, v[cnt.first][cnt.second]);
        if (matrix[cnt.first][cnt.second] == '^') {
            dfs(matrix, v, make_pair(cnt.first - 1, cnt.second), end, ans);
            dfs(matrix, v, make_pair(cnt.first, cnt.second - 1), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first + 1, cnt.second), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first, cnt.second + 1), end, ans + 1);
        }
        else if (matrix[cnt.first][cnt.second] == 'v') {
            dfs(matrix, v, make_pair(cnt.first - 1, cnt.second), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first, cnt.second - 1), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first + 1, cnt.second), end, ans);
            dfs(matrix, v, make_pair(cnt.first, cnt.second + 1), end, ans + 1);
        }
        else if (matrix[cnt.first][cnt.second] == '<') {
            dfs(matrix, v, make_pair(cnt.first - 1, cnt.second), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first, cnt.second - 1), end, ans);
            dfs(matrix, v, make_pair(cnt.first + 1, cnt.second), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first, cnt.second + 1), end, ans + 1);
        }
        else if (matrix[cnt.first][cnt.second] == '>') {
            dfs(matrix, v, make_pair(cnt.first - 1, cnt.second), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first, cnt.second - 1), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first + 1, cnt.second), end, ans + 1);
            dfs(matrix, v, make_pair(cnt.first, cnt.second + 1), end, ans);
        }
    }
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        row = matrix.size(), col = matrix[0].size();
        mins = abs(start[0] - end[0]) + abs(start[1] - end[1]);
        vector<vector<int>> v(row, vector<int>(col, mins));
        pair<int, int> ss = make_pair(start[0], start[1]), ee = make_pair(end[0], end[1]);
        if (ss == ee) {
            return 0;
        }
        sol = mins;
        dfs(matrix, v, ss, ee, 0);
        return sol;
    }
};