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

// 最大和上升子序列

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
        dp[i] = nums[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + nums[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}