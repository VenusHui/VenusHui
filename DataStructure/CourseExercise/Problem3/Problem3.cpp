// 勇闯迷宫游戏
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 迷宫类
class Maze
{
private:
    int row, col;   // 行数及列数
    char **MazeMap; // 指向整张地图
    bool **visited; // 用于确定每个点是否被访问

public:
    int startX, startY, endX, endY;     // 起点及终点坐标
    bool dfs(int start_x, int start_y); // 深度优先搜索路径
    void printMap();                    // 打印地图
    Maze();
    ~Maze();
};

Maze::Maze()
{
    int oper; // 用于确定用户是否需要自行输入地图
    cout << "if your want to use the fixed maze map, please INPUT 1, or INPPUT ANYTHING ELSE to input the map by yourself!" << endl;
    cin >> oper;
    row = col = 6;
    startX = 5;
    startY = 3;
    endX = 0;
    endY = 3;
    char map[6][6] = {{'0', '#', '#', '0', '0', '#'},
                      {'#', '#', '0', '0', '#', '#'},
                      {'#', '0', '0', '#', '0', '#'},
                      {'0', '0', '#', '#', '0', '#'},
                      {'#', '0', '#', '#', '0', '#'},
                      {'#', '0', '0', '0', '#', '#'}};
    if (oper != 1)
    {
        cout << "Please input the row and the colomn num of the Maze:" << endl;
        cin >> row >> col;
    }
    MazeMap = new char *[row];
    visited = new bool *[row];
    for (int i = 0; i < row; i++)
    {
        MazeMap[i] = new char[col];
        visited[i] = new bool[col];
        if (oper == 1)
        {
            for (int j = 0; j < col; j++)
            {
                MazeMap[i][j] = map[i][j];
                visited[i][j] = false;
            }
        }
    }
    if (oper != 1)
    {
        cout << "Please input the Maze ,'#' refers to unavilible node while '0' refers to avilible node:" << endl;
        for (int i = 0; i < row; i++)
        {
            char ch = getchar();
            if (ch != '\n')
            {
                cout << "input error" << endl;
            }
            for (int j = 0; j < col; j++)
            {
                visited[i][j] = false;
                MazeMap[i][j] = getchar();
            }
        }
        cout << "Please input the start position and the end position:" << endl;
        cin >> endX >> endY >> startX >> startY;
        if (MazeMap[startX][startY] != '0' || MazeMap[endX][endY] != '0') // 选择的起点、终点为不可走的
        {
            cout << "the start node or the end node is not avilible, please check the input" << endl;
        }
    }
}

Maze::~Maze()
{
    // 释放内存
    for (int i = 0; i < row; i++)
    {
        delete MazeMap[i];
        delete visited[i];
    }
    delete[] MazeMap;
    delete[] visited;
}

bool Maze::dfs(int start_x, int start_y)
{
    // 触碰边界
    if (start_x < 0 || start_y < 0 || endX < 0 || endY < 0 || start_x >= row || start_y >= col || endX >= row || endY >= col)
    {
        return false;
    }
    // 不可访问或已访问过
    if (MazeMap[start_x][start_y] == '#' || visited[start_x][start_y] == true)
    {
        return false;
    }
    visited[start_x][start_y] = true; // 将该位置标记为已访问
    if (dfs(start_x - 1, start_y))    // 访问左边
    {
        cout << "(" << start_x - 1 << ", " << start_y << ")"
             << " ---> ";
        MazeMap[start_x - 1][start_y] = '*';
        return true;
    }
    else if (dfs(start_x, start_y - 1)) // 访问下边
    {
        cout << "(" << start_x << ", " << start_y - 1 << ")"
             << " ---> ";
        MazeMap[start_x][start_y - 1] = '*';
        return true;
    }
    else if (dfs(start_x + 1, start_y)) // 访问右边
    {
        cout << "(" << start_x + 1 << ", " << start_y << ")"
             << " ---> ";
        MazeMap[start_x + 1][start_y] = '*';
        return true;
    }
    else if (dfs(start_x, start_y + 1)) // 访问上边
    {
        cout << "(" << start_x << ", " << start_y + 1 << ")"
             << " ---> ";
        MazeMap[start_x][start_y + 1] = '*';
        return true;
    }
    if (start_x == endX && start_y == endY) // 到达终点
    {
        MazeMap[start_x][start_y] = '*';
        return true;
    }
    return false;
}

void Maze::printMap()
{
    const int gap = 8;
    cout << setw(gap - 4) << ' ';
    for (int i = 0; i < col; i++)
    {
        cout << setw(gap - 2) << i << "列";
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        cout << i << "行";
        for (int j = 0; j < col; j++)
        {
            cout << setw(gap) << MazeMap[i][j];
        }
        cout << endl;
    }
}

int main()
{
    Maze map;
    if (!map.dfs(map.startX, map.startY))
    {
        cout << "No Answer!" << endl;
    }
    else
    {
        cout << "(" << map.startX << ", " << map.startY << ")" << endl;
        map.printMap();
    }
    return 0;
}
