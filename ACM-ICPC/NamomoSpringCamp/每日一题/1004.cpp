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
#include <unordered_map>
#include <stack>
#include <set>
#include <numeric>
#include <iomanip>
typedef long long ll;
using namespace std;

// 简单子段和

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, k, ans = 0;
    cin >> n >> k;
    unordered_map<ll, ll> mp;
    mp[0] = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        sum += num;
        ans += mp[sum - k];
        mp[sum]++;
    }
    cout << ans << '\n';
    
    return 0;
}
