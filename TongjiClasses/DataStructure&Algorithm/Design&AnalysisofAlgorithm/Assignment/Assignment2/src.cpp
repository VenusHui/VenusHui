/*************************
 *   Writer: 2053300 胡锦晖
 *   Date: 2022-05-02
 **************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
typedef long long ll;
using namespace std;

// Assignment2

void sudokuPuzzleSolver(vector<vector<char>> &board) {
  const int size = 9; // 行和列的大小

  // row、col、sec分别表示每一行、每一列、每个九宫格中 1~9 的数字有没有被使用过
  vector<vector<bool>> row(size, vector<bool>(size, false));
  vector<vector<bool>> col(size, vector<bool>(size, false));
  vector<vector<vector<bool>>> sec(
      3, vector<vector<bool>>(3, vector<bool>(size, false)));

  // 初始化row、col、sec数组
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] != ' ') {
        // 若当前位置已经有数字，就将row、col、sec对应位置置为true表示该数字已经被使用
        row[i][board[i][j] - '1'] = true;
        col[j][board[i][j] - '1'] = true;
        sec[i / 3][j / 3][board[i][j] - '1'] = true;
      }
    }
  }

  // 从第r行第c列递归求解问题
  function<bool(int, int)> dfs = [&](int r, int c) {
    if (c >= size) {
      // 求解完一行后，开始求解下一行
      c = 0, r++;
      if (r >= size) {
        // 此时所有位置已求解完毕，返回true
        return true;
      }
    }

    // 若当前位置就可以填入数字
    if (board[r][c] == ' ') {
      // 从1到9枚举该位置可以填入的数字
      for (int i = 0; i < 9; i++) {
        // 若该数字在row、col、sec数组中都没有被使用过，则说明可以填
        if (!row[r][i] && !col[c][i] && !sec[r / 3][c / 3][i]) {
          // 填入数字并更新相应的row、col、sec数组
          board[r][c] = static_cast<char>('1' + i);
          row[r][i] = true;
          col[c][i] = true;
          sec[r / 3][c / 3][i] = true;

          if (dfs(r, c + 1)) {
            // 递归地求解下一个位置，如果下一个位置（从最后一个位置回溯
            // 上来）求解成功，说明本次填入的数可以作为可行解，返回true
            return true;
          } else {
            // 若下一个位置求解不成功，则说明本次填入不可行，将本次的填入操作回退
            board[r][c] = ' ';
            row[r][i] = false;
            col[c][i] = false;
            sec[r / 3][c / 3][i] = false;
          }
          // 去找下一个数尝试填入
        }
      }
    } else {
      // 若当前位置已经有预先填好的数字，则直接求解下一个位置
      return dfs(r, c + 1);
    }
    return false;
  };

  // 从第0行第0列开始求解问题
  dfs(0, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int size = 9; // 行和列的大小
  string line;
  vector<vector<char>> board(size, vector<char>(size));

  // 获取输入
  int row = 0, col = 0; // 从第0行第0列开始输入，当超过第size行时输入结束
  while (row < size) {
    getline(cin, line); // 读取一行

    // 遍历输入的字符串，如果是数字或者为空的话就将其添加到board中
    int lsize = line.size();
    for (int i = 0; i < lsize; i++) {
      if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9')) {
        board[row][col++] = line[i];
      }
    }

    // 从下一行的第0列获取输入
    row++, col = 0;
  }

  // 求解
  sudokuPuzzleSolver(board);

  // 输出，为方便在控制台中分隔输入和输出，这里在输出之前多进行一次换行
  cout << '\n' << "[";
  for (int i = 0; i < size; i++) {
    cout << "[";
    for (int j = 0; j < size; j++) {
      cout << "\"" << board[i][j] << "\"";
      if (j != size - 1) {
        cout << ",";
      }
    }
    if (i != size - 1) {
      cout << "]," << '\n';
    } else {
      cout << "]]" << '\n';
    }
  }

  return 0;
}

// Test Data

// [["1"," "," ","4","5","6","3","7","2"],
// ["7","3","6","8"," "," "," "," ","5"],
// [" ","2"," ","7"," ","9","1"," ","8"],
// ["6","4"," "," "," ","8","7","5"," "],
// [" ","8","2"," "," ","5"," "," "," "],
// ["5"," ","1","6"," ","3","8"," "," "],
// ["3","5","7","2","9","1"," ","8","4"],
// [" "," "," ","5"," ","7"," "," ","3"],
// ["2"," "," ","3","8"," "," "," "," "]]