#include <iostream>
#include <cmath>
using namespace std;

class NQueenSol
{
private:
    int ans, qNum;    // 记录解法个数以及皇后个数
    int *placeResult; // 记录每一行皇后所在的列号，从1开始。

public:
    NQueenSol();
    ~NQueenSol();
    bool isSafe(int row, int col); // 判断(row, col)位置能否放置皇后
    void place(int row);           // 放置皇后
    void printSolution();          // 打印该种解法
};

NQueenSol::NQueenSol()
{
    ans = 0;
    cout << "现有N * N的棋盘，放入N个皇后，要求所有皇后不在同一行、列和同一斜线上" << endl;
    cout << "请输入皇后的个数：";
    cin >> qNum;
    if (cin.fail())
    {
        throw "input error";
    }
    try
    {
        placeResult = new int[qNum + 1];
        for (int i = 0; i < qNum + 1; i++)
        {
            placeResult[i] = 0;
        }
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << endl;
        exit(0);
    }
}

NQueenSol::~NQueenSol()
{
    delete[] placeResult;
}

bool NQueenSol::isSafe(int row, int col)
{
    int i = 1;
    while (i < row)
    {
        if (placeResult[i] == col || abs(row - i) == abs(placeResult[i] - col))
        {
            return false;
        }
        i++;
    }
    return true;
}

void NQueenSol::place(int row)
{
    if (row > qNum)
    {
        printSolution();
    }
    else
    {
        for (int i = 1; i <= qNum; i++)
        {
            if (isSafe(row, i))
            {
                placeResult[row] = i;
                place(row + 1);
            }
        }
    }
}

void NQueenSol::printSolution()
{
    ans++;
    cout << "第 " << ans << " 种解法为：" << endl;
    for (int i = 1; i <= qNum; i++)
    {
        for (int j = 1; j <= qNum; j++)
        {
            if (j != placeResult[i])
            {
                cout << "0 ";
            }
            else
            {
                cout << "1 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    NQueenSol solution;
    solution.place(1);
    return 0;
}