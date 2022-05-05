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

// Codeforces Round #784 (Div. 4) H. Maximal AND

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    const int m = 31;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cal(m + 1);
        vector<bool> res(m + 1);
        for (int i = 0; i < n; i++) {
            int num, pos = 1;
            cin >> num;
            while (num) {
                cal[pos++] += num % 2;
                num /= 2;
            }
        }
        for (int i = m; i >= 1; i--) {
            int sub = n - cal[i];
            if (k - sub >= 0) {
                k -= sub;
                res[i] = true;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            if (res[i]) {
                ans += 1 << (i - 1);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
