/*********************************
 *  Codeforces Round #789 (Div. 2) C
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Verdict: TLE
 *  Date: 2022-05-08
*********************************/
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
        int n;
        cin >> n;
        vector<int> p(n);
        vector<vector<int>> res(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int tmp = 0;
                for (int k = j + 1; k < n; k++) {
                    if (p[k] < p[i]) {
                        tmp++;
                    }
                }
                res[i][j] = tmp;
            }
        }
        ll ans = 0;
        for (int a = 0; a < n - 3; a++) {
            for (int c = a + 2; c < n - 1; c++) {
                if (p[a] < p[c]) {
                    for (int b = a + 1; b < c; b++) {
                        ans += res[b][c];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
