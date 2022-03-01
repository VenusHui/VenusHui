// 最长上升子序列
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
    vector<int> a(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = dp[0];
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }
    cout << ans << endl;

    return 0;
}