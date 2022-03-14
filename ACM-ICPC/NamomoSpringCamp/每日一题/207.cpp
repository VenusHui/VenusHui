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

// 01序列

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    string s;
    cin >> k >> s;
    int size = s.size();
    vector<pair<pair<int, int>, int> > res(size);
    int pre = 0; // 记录这一个的pre和上一个的end
    int tmp = -1;
    for (int i = 0; i < size; i++)
    {
        if (s[i] != '1')
        {
            pre++;
            res[i].second = 0;
        }
        if (s[i] == '1')
        {
            res[i].second = 1;
            res[i].first.first = pre;
            if (tmp >= 0)
                res[tmp].first.second = pre;
            pre = 0;
            tmp = i;
        }
    }
    if (tmp == -1)
        tmp = size - 1;
    res[tmp].first.second = pre;
    ll ans = 0;
    if (k == 0)
    {
        int i = 0, j = 0;
        for (i = 0; i < size; i++)
        {
            if (res[i].second == 1)
            {
                ans += (ll(res[i].first.first + 1) * ll(res[i].first.first) / 2);
                j = i;
            }
        }
        if (j == 0)
            j = size - 1;
        ans += (ll(res[j].first.second + 1) * ll(res[j].first.second) / ll(2));
        cout << ans << '\n';
        return 0;
    }
    // 滑动窗口
    int l = 0, r = 0;
    for (l = 0; l < size; l++)
        if (res[l].second == 1)
            break;
    for (r = l; r < size; r++)
    {
        if (res[r].second == 1)
            k--;
        if (k == 0)
            break;
    }
    while (r < size)
    {
        ans += (res[l].first.first + 1) * (res[r].first.second + 1);
        l++;
        r++;
        while (res[l].second != 1 && l <= r)
            l++;
        while (res[r].second != 1 && r < size)
            r++;
    }
    cout << ans << '\n';

    return 0;
}