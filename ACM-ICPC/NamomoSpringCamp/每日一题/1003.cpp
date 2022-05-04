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
#include <stack>
#include <set>
#include <iomanip>
typedef long long ll;
#define endl '\n';
using namespace std;

// 分数拆分

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll k, ans = 0;
    cin >> k;
    for (ll y = k + 1; y <= 2 * k; y++) {
        if (1LL * y * k % (y - k) == 0) {
            ans++;
        }
    }
    cout << ans << '\n';
    
    return 0;
}