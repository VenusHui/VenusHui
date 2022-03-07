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

// Codeforces Round #775 (Div. 2) B. Game of Ball Passing

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> res(n);
        for (int i = 0; i < n; i++)
            cin >> res[i];
        sort(res.begin(), res.end());
        if (res[n - 1] == 0)
        {
            cout << "0" << '\n';
            continue;
        }
        for (int i = 0; i < n - 1; i++)
            res[n - 1] -= res[i];
        if (res[n - 1] <= 0)
            cout << "1" << '\n';
        else
            cout << res[n - 1] << '\n';
    }
    return 0;
}