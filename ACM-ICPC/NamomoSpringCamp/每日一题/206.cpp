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

// 异或和或

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string src, aim;
        cin >> src >> aim;
        int size = src.size() == aim.size() ? src.size() : -1;
        if (size == -1)
        {
            cout << "NO" << '\n';
            continue;
        }
        bool srcFlag = false, aimFlag = false;
        for (int i = 0; i < size; i++)
        {
            if (src[i] == '1')
                srcFlag = true;
            if (aim[i] == '1')
                aimFlag = true;
        }
        if (srcFlag == aimFlag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        
    }

    return 0;
}