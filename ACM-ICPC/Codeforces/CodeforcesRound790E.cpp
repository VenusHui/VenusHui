/***********************************
 *  Codeforces Round #790 (Div. 4)
 *  E. Eating Queries
 *  Writer: VenusHui    
 *  Version: Contest Version
 *  Date: 2022-05-11
***********************************/
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
#include <functional>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> res(n), pre(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
        }
        sort(res.begin(), res.end(), [&](int a, int b) {
            return a > b;
        });
        partial_sum(res.begin(), res.end(), pre.begin());
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (x > pre[n - 1]) {
                cout << "-1" << '\n';
                continue;
            }
            else if (x == 0) {
                cout << "0" << '\n';
                continue;
            }
            int l = 0, r = n - 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (pre[m] < x) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            cout << l + 1 << '\n';
        }
    }

    return 0;
}
