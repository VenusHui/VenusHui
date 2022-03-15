#include <iostream>
#include <cstdio>
#include <fstream>
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

// 整齐的数组
// 未完成

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if (i >= 1 && nums[i] != nums[i - 1])
                flag = false;
        }
        if (flag)
        {
            cout << "-1" << '\n';
            continue;
        }
        
    }
    return 0;
}