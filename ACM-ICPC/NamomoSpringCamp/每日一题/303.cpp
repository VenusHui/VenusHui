#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <unordered_set>
#include <iomanip>
typedef long long ll;
#define endl '\n';
using namespace std;

// 网格判断

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> mp(n);
    for (int i = 0; i < n; i++)
        cin >> mp[i];
    bool win = true;
    // 按行处理
    for (int i = 0; i < n; i++)
    {
        int bNum = 0, wNum = 0, aRow = 1;
        if (mp[i][0] == 'B')
            bNum++;
        else
            wNum++;
        for (int j = 1; j < n; j++)
        {
            if (mp[i][j] == 'B')
                bNum++;
            else if (mp[i][j] == 'W')
                wNum++;
            if (mp[i][j] == mp[i][j - 1])
            {
                aRow++;
                if (aRow >= 3)
                    win = false;
            }
            else
                aRow = 1;
        }
        if (bNum != wNum)
            win = false;
    }
    // 按列处理
    for (int j = 0; j < n; j++)
    {
        int bNum = 0, wNum = 0, aRow = 1;
        if (mp[0][j] == 'B')
            bNum++;
        else
            wNum++;
        for (int i = 1; i < n; i++)
        {
            if (mp[i][j] == 'B')
                bNum++;
            else if (mp[i][j] == 'W')
                wNum++;
            if (mp[i][j] == mp[i - 1][j])
            {
                aRow++;
                if (aRow >= 3)
                    win = false;
            }
            else
                aRow = 1;
        }
        if (bNum != wNum)
            win = false;
    }

    if (win)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}