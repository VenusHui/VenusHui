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

// Codeforces Round #776 (Div. 3) C.Weight of the System of Nested Segments

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
        ll sum = 0;
        vector<pair<pair<int, int>, int> > res(m); // 收益、位置、编号
        vector<pair<pair<int, int>, int> > ans(2 * n);
        for (int i = 0; i < m; i++)
        {
            cin >> res[i].first.second >> res[i].first.first;
            res[i].second = i + 1;
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < 2 * n; i++)
        {
            sum += res[i].first.first;
            swap(res[i].first.first, res[i].first.second);
            ans[i] = res[i];
        }
        sort(ans.begin(), ans.end());
        cout << sum << '\n';
        for (int i = 0; i < n; i++)
            cout << ans[i].second << " " << ans[2 * n - 1 - i].second << '\n';
    }
    return 0;
}
