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

// 子串分值和

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll size = s.size();
    vector<ll> tmp;
    vector<vector<ll>> res(26);
    for (ll i = 0; i < size; i++)
        res[s[i] - 'a'].push_back(i);
    ll ans = 0;
    for (ll i = 0; i < 26; i++)
    {
        ll sum = size * (size + 1) / 2;
        ll rsize = res[i].size();
        if (rsize == 0)
            continue;
        ll tmp = -1;
        ll sct = 0;
        for (ll j = 0; j < rsize; j++)
        {
            sct += ((res[i][j] - tmp - 1) * (res[i][j] - tmp) / 2);
            tmp = res[i][j];
        }
        if (rsize)
            sct += ((size - tmp - 1) * (size - tmp) / 2);
        sum -= sct;
        ans += sum;
        
    }
    cout << ans << '\n';

    return 0;
}