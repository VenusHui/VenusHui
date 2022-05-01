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

// 异或和

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    vector<ll> res(60, 0);
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        vector<int> tmp;
        while (num) {
            tmp.push_back(num % 2);
            num /= 2;
        }
        int tsize = tmp.size();
        for (int j = 0; j < tsize; j++) {
            res[j] += tmp[j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < 60; i++) {
        ans = (ans + (1LL << i) % mod * (res[i] * (n - res[i]) % mod)) % mod;
    }
    cout << ans % mod << '\n';
    
    return 0;
}
