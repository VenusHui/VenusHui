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
#include <unordered_set>
#include <iomanip>
typedef long long ll;
using namespace std;

// Codeforces Round #777 (Div. 2) B. Madoka and the Elegant Gift

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> mp(n);
        for (int i = 0; i < n; i++)
            cin >> mp[i];

        bool ans = true;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (mp[i][j] + mp[i + 1][j] + mp[i][j + 1] + mp[i + 1][j + 1] - 4 * '0' == 3)
                {
                    ans = false;
                    break;
                }
            }
        }
        if (ans)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}