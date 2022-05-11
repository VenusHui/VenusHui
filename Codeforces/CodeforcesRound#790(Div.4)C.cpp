/***********************************
 *  Codeforces Round #790 (Div. 4)
 *  C. Most Similar Words
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

inline int calc(string a, string b) {
    int size = a.size(), ans = 0;
    for (int i = 0; i < size; i++) {
        ans += abs(a[i] -b[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
        }
        int ans = 1e9 + 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = min(ans, calc(res[i], res[j]));
            }
        }
        if (ans > 1e9) {
            cout << "0" << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
