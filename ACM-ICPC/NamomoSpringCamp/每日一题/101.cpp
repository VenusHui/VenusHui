// 特殊三角形
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
#include <stack>
#include <set>
#include <iomanip>
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    // initialize
    string tmp;
    vector<string> res;
    bool isSq = true;
    for (int i = 0; i < n; i++)
    {
        tmp += '+';
    }
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        for (int j = i - 1; j < n - i + 1; j++)
        {
            if (isSq)
            {
                tmp[j] = '+';
            }
            else
            {
                tmp[j] = '.';
            }
        }
        cout << tmp << endl;
        res.push_back(tmp);
        isSq = !isSq;
    }
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        cout << res[i] << endl;
    }

    return 0;
}