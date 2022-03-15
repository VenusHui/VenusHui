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

// Educational Codeforces Round 124 (Div. 2) C. Fault-tolerant Network

int n;
const int maxNum = 2e5 + 1;
inline int absMin(vector<int> &res, int num)
{
    int tmp = 1e9 + 1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (tmp > abs(res[i] - num))
        {
            tmp = abs(res[i] - num);
            index = i;
        }
    }
    return index;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        ll ans = 1e10;
        vector<int> afunc = {0, absMin(b, a[0]), n - 1};
        vector<int> bfunc = {0, absMin(b, a[n - 1]), n - 1};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ll tmp = static_cast<ll>(abs(a[0] - b[afunc[i]]) + abs(a[n - 1] - b[bfunc[j]]));
                if (afunc[i] > 0 && bfunc[j] > 0)
                    tmp += abs(b[0] - a[absMin(a, b[0])]);
                if (afunc[i] < n - 1 && bfunc[j] < n - 1)
                    tmp += abs(b[n - 1] - a[absMin(a, b[n - 1])]);
                
                ans = min(ans, tmp);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}