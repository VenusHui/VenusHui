#include <iostream>
#include <string>
using namespace std;

const int N = 1e3 + 5;
char mazzMap[N][N];
bool visited[N][N];
void dfs(int start_x, int start_y, int end_x, int end_y)
{
	if (mazzMap[start_x][start_y] == '#' || visited[start_x][start_y] == true || start_x < 0 || start_y < 0 || end_x < 0 || end_y < 0)
	{
		return;
	}
	visited[start_x][start_y] = true;
	cout << "(" << start_x << ", " << start_y << ")" << " ---> ";
	if (start_x - 1 == end_x && start_y == end_y)
	{
		cout << "(" << start_x - 1 << ", " << start_y << ")" << endl;
		return;
	}
	else
	{
		dfs(start_x - 1, start_y, end_x, end_y);
	}
	if (start_x + 1 == end_x && start_y == end_y)
	{
		cout << "(" << start_x + 1 << ", " << start_y << ")" << endl;
		return;
	}
	else
	{
		dfs(start_x + 1, start_y, end_x, end_y);
	}
	if (start_x == end_x && start_y - 1 == end_y)
	{
		cout << "(" << start_x << ", " << start_y - 1 << ")" << endl;
		return;
	}
	else
	{
		dfs(start_x, start_y - 1, end_x, end_y);
	}
	if (start_x == end_x && start_y + 1 == end_y)
	{
		cout << "(" << start_x << ", " << start_y + 1 << ")" << endl;
		return;
	}
	else
	{
		dfs(start_x, start_y + 1, end_x, end_y);
	}
}

int main()
{
	 // declaration, inputs and initialization
	int row, col, startX, startY, endX, endY;
	cout << "Please input the row and the colomn num of the mazz:" << endl;
	cin >> row >> col;
	
	cout << "Please input the mazz ,'#' refers to unavilible node while '0' refers to avilible node:" << endl;
	for (int i = 0; i < row; i++)
	{
		char ch = getchar();
		for (int j = 0; j < col; j++)
		{
			mazzMap[i][j] = getchar();
		}
	}
	cout << "Please input the start position and the end position:" << endl;
	cin >> startX >> startY >> endX >> endY;
	if (mazzMap[startX][startY] != '0' || mazzMap[endX][endY] != '0')
	{
		cout << "the start node or the end node is not avilible, please check the input" << endl;
	}
	// dfs
	dfs(startX, startY, endX, endY);

	// deletion
	return 0;
}
