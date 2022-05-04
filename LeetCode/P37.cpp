// 37. 解数独
class Solution {
private:
    const int size = 9;
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<vector<bool>>> sec;
    inline bool dfs(vector<vector<char>>& board, int r, int c) {
        if (c >= size) {
            c = 0, r++;
            if (r >= size) {
                return true;
            }
        }
        if (board[r][c] == '.') {
            for (int i = 0; i < 9; i++) {
                if (!row[r][i] && !col[c][i] && !sec[r / 3][c / 3][i]) {
                    board[r][c] = static_cast<char>('1' + i);
                    row[r][i] = true;
                    col[c][i] = true;
                    sec[r / 3][c / 3][i] = true;
                    if (dfs(board, r, c + 1)) {
                        return true;
                    }
                    else {
                        board[r][c] = '.';
                        row[r][i] = false;
                        col[c][i] = false;
                        sec[r / 3][c / 3][i] = false;
                    }
                }
            }
        }
        else {
            return dfs(board, r, c + 1);
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<bool>>(9, vector<bool>(9, false));
        col = vector<vector<bool>>(9, vector<bool>(9, false));
        sec = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = true;
                    col[j][board[i][j] - '1'] = true;
                    sec[i / 3][j / 3][board[i][j] - '1'] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
};
