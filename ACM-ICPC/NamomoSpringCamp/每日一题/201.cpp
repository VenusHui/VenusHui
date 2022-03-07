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

// 任务分配

const int maxNum = 1e3;
int dp[maxNum + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > tasks(n); // 开始时间，完成时间，收益
    for (int i = 0; i < n; i++)
        cin >> tasks[i].first.first >> tasks[i].first.second >> tasks[i].second;

    // 动态规划
    for (int i = 1; i <= maxNum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == tasks[j].first.second)
                dp[i] = max(dp[i], dp[tasks[j].first.first] + tasks[j].second);
            else
                dp[j] = max(dp[j], dp[j - 1]);
        }
    }
    int ans = dp[0];
    for (int i = 1; i <= maxNum; i++)
        ans = max(ans, dp[i]);

    cout << ans << '\n';
    return 0;
}