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

// 切割

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> res(n);
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; i++) {
        cin >> res[i];
        q.push(res[i]);
    }
    ll ans = 0;
    while (q.size() != 1) {
        ll res = 0;
        res += q.top();
        q.pop();
        res += q.top();
        q.pop();
        q.push(res);
        ans += res;
    }
    cout << ans << '\n';
    
    return 0;
}
