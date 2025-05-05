#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class NQueenSol {
private:
  int ans, qNum;    // 记录解法个数以及皇后个数
  int *placeResult; // 记录每一行皇后所在的列号，从1开始。

public:
  NQueenSol();
  ~NQueenSol();
  void input(int &data, const string cueStr, int low = 1, int high = INT_MAX);
  bool isSafe(int row, int col); // 判断(row, col)位置能否放置皇后
  void place(int row);           // 放置皇后
  void printSolution();          // 打印该种解法
  int getAns() { return ans; }
};

NQueenSol::NQueenSol() {
  ans = 0;
  cout << "现有N * N的棋盘，放入N个皇后，要求所有皇后不在同一行、列和同一斜线上"
       << endl;
  input(qNum, "皇后个数", 1, 15);
  placeResult = new int[qNum + 1];
  for (int i = 0; i < qNum + 1; i++) {
    placeResult[i] = 0;
  }
}

NQueenSol::~NQueenSol() { delete[] placeResult; }

void NQueenSol::input(int &data, const string cueStr, int low, int high) {
  bool loop = true;
  while (loop) {
    cout << "请输入" << cueStr << "：";
    cin >> data;
    if (cin.fail() || data < low || data > high) {
      cin.clear();
      cin.ignore(65536, '\n');
      cout << "输入" << cueStr << "不合法，请检查后重新输入" << endl;
      continue;
    }
    loop = false;
  }
}

bool NQueenSol::isSafe(int row, int col) {
  int i = 1;
  while (i < row) {
    if (placeResult[i] == col || abs(row - i) == abs(placeResult[i] - col)) {
      return false;
    }
    i++;
  }
  return true;
}

void NQueenSol::place(int row) {
  if (row > qNum) {
    printSolution();
  } else {
    for (int i = 1; i <= qNum; i++) {
      if (isSafe(row, i)) {
        placeResult[row] = i;
        place(row + 1);
      }
    }
  }
}

void NQueenSol::printSolution() {
  ans++;
  cout << "第 " << ans << " 种解法为：" << endl;
  for (int i = 1; i <= qNum; i++) {
    for (int j = 1; j <= qNum; j++) {
      if (j != placeResult[i]) {
        cout << "0 ";
      } else {
        cout << "1 ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  clock_t start, finish;
  start = clock();
  NQueenSol solution;
  solution.place(1);
  if (solution.getAns() == 0) {
    cout << "此情况下无解" << endl;
  }
  finish = clock();
  double duration = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
  cout << "所用时间：" << duration << " s" << endl;
  return 0;
}