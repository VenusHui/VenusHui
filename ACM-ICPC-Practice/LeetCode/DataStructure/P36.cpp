// 36. 有效的数独
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int size = 9;
        vector<vector<bool>> row(size, vector<bool>(size));
        vector<vector<bool>> col(size, vector<bool>(size));
        vector<vector<vector<bool>>> sec(size / 3, vector<vector<bool>>(size / 3, vector<bool>(size)));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (row[i][board[i][j] - '1'] || col[j][board[i][j] - '1'] || sec[i / 3][j / 3][board[i][j] - '1']) {
                    return false;
                }
                row[i][board[i][j] - '1'] = true;
                col[j][board[i][j] - '1'] = true;
                sec[i / 3][j / 3][board[i][j] - '1'] = true;
            }
        }
        return true;
    }
};