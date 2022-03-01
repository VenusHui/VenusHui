// 走路
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

int dp[101][100001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > res(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> res[i].first >> res[i].second;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i - 1][j] == 1)
            {
                if (j + res[i].first <= m)
                    dp[i][j + res[i].first] = 1;
                if (j + res[i].second <= m)
                    dp[i][j + res[i].second] = 1;
            }
        }
    }
    for (int i = 0; i <= m; i++)
        cout << dp[n][i];
    cout << endl;

    return 0;
}