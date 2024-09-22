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

// Codeforces Round #775 (Div. 2) C. Wierd Sum

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int **res = new int *[n];
    for (int i = 0; i < n; i++)
        res[i] = new int[m];
    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> res[i][j];
            maxNum = max(maxNum, res[i][j]);
        }
    }
    vector<vector<pair<int, int> > > mp(maxNum + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mp[res[i][j]].push_back(make_pair(i + 1, j + 1));
    ll ans = 0;
    for (int i = 1; i <= maxNum; i++)
    {
        int size = mp[i].size();
        if (size)
        {
            sort(mp[i].begin(), mp[i].end());
            for (int j = size - 1; j >= 0; j--)
                ans += static_cast<ll>(2 * j + 1 - size) * static_cast<ll>(mp[i][j].first);
            sort(mp[i].begin(), mp[i].end(), cmp);
            for (int j = size - 1; j >= 0; j--)
                ans += static_cast<ll>(2 * j + 1 - size) * static_cast<ll>(mp[i][j].second);
        }
    }
    cout << ans << '\n';
    return 0;
}