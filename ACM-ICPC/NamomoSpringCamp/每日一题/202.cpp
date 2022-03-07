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
using namespace std;

// 路径计数

const int maxNum = 100;
const ll mod = 1e9 + 7;
ll dp[maxNum + 1][maxNum + 1];
bool mp[maxNum + 1][maxNum + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mp[i][j];
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (mp[i][j])
            {
                if (i - 1 > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j - 1 > 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
    cout << dp[n][n] << '\n';

    return 0;
}