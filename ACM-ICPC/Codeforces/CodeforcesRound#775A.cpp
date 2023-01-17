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

// Codeforces Round #775 (Div. 2) A. Game

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
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            cin >> res[i];
        int ans = 0;
        int start = 0, end = -2;
        for (int i = 0; i < n; i++)
            if (res[i] == 0)
            {
                start = i;
                break;
            }
        for (int i = n - 1; i >= 0; i--)
            if (res[i] == 0)
            {
                end = i;
                break;
            }
        ans = end - start + 2;
        cout << ans << '\n';
    }

    return 0;
}