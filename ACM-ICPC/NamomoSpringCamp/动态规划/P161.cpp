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

// 01背包问题
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > obj(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> obj[i].first >> obj[i].second;
    vector<int> dp(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= obj[i].first; j--)
            dp[j] = max(dp[j], dp[j - obj[i].first] + obj[i].second);
    }
    cout << dp[m] << '\n';

    return 0;
}