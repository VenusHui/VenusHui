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

// 完美数

const ll mod = 1e9 + 7;
const int maxNum = 1e6 + 1;
int a, b, m;
ll fact[maxNum], infact[maxNum];

bool check(int num) {
    while (num) {
        int tmp = num % 10;
        if (tmp != a && tmp != b) {
            return false;
        }
        num /= 10;
    }
    return true;
}

ll calc(int a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * static_cast<ll>(a) % mod;
        b >>= 1;
    }
    return ans;
}

int com(int a, int b) {
    return (fact[a] * infact[b] % mod * infact[a - b] % mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    cin >> a >> b >> m;
    fact[0] = infact[0] = 1;
    for (int i = 1; i < maxNum; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    infact[maxNum - 1] = calc(fact[maxNum - 1], mod - 2);
    for (int i = maxNum - 2; i; i--) {
        infact[i] = infact[i + 1] * (i + 1) % mod;
    }
    ll ans = 0;
    int sum = m * a;
    for (int i = 0; i <= m; i++) {
        if (i) {
            sum = sum - a + b;
        }
        if (check(sum)) {
            ans = (ans + com(m, i)) % mod;
        }
    }
    cout << ans << '\n';

    return 0;
}
