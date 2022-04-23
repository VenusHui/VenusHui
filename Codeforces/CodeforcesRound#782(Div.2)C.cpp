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

// Codeforces Round #782 (Div. 2) C. Line Empire

// Tutorial Version

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<ll> x(n + 1), p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            p[i] = p[i - 1] + x[i];
        }
        // 可以用partial_sum方法求前缀和：
        // partial_sum(x.begin(), x.end(), p.begin());
        ll ans = 1e18 + 1;
        // 枚举最后capital的位置
        for (int i = 0; i <= n; i++) {
            ans = min(ans, (a + b) * (x[i] - x[0]) + b * (p[n] - p[i] - (n - i) * x[i]));
        }
        cout << ans << '\n';
    }
    
    return 0;
}
