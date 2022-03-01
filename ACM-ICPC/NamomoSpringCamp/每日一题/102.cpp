// 走楼梯2
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

ll dp[51][3];
int main()
{
    int n;
    cin >> n;
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] - dp[i - 2][1] - dp[i - 2][2];
        dp[i][2] = dp[i - 2][1];
    }
    cout << dp[n][0] + dp[n][1] + dp[n][2] << endl;

    return 0;
}