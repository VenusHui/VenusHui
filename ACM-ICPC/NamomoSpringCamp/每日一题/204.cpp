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
#define endl '\n';
using namespace std;

// 加一

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 打表
    const ll maxNum = 2e5;
    const ll mod = 1e9 + 7;
    vector<vector<vector<ll> > > res(10);
    for (int i = 0; i < 10; i++)
    {
        vector<ll> tmp(10);
        tmp[i] = 1;
        for (int j = 0; j <= maxNum; j++)
        {
            ll a = tmp[9] % mod;
            for (int k = 8; k >= 0; k--)
                tmp[k + 1] = tmp[k] % mod;
            tmp[0] = a % mod;
            tmp[1] += a % mod;
            res[i].push_back(tmp);
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int m;
        string n;
        cin >> n >> m;
        vector<ll> nums(10);
        int size = n.size();
        for (int i = 0; i < size; i++)
            nums[n[i] - '0']++;
        ll ans = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                ans += nums[i] * res[i][m - 1][j];
            }
            ans = ans % mod;
        }
        cout << ans << '\n';
    }

    return 0;
}