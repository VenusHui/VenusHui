/***********************************
 *  Codeforces Round #790 (Div. 4)
 *  D. X-Sum
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

inline int calc(vector<vector<int>>& res, int r, int c) {
    int n = res.size(), m = res[0].size();
    int ans = 0;
    pair<int, int> pos = make_pair(r, c);
    while (true) {
        pos.first--;
        pos.second--;
        if (pos.first >= 0 && pos.second >= 0 && pos.first < n && pos.second < m) {
            ans += res[pos.first][pos.second];
        }
        else {
            break;
        }
    }
    pos = make_pair(r, c);
    while (true) {
        pos.first++;
        pos.second--;
        if (pos.first >= 0 && pos.second >= 0 && pos.first < n && pos.second < m) {
            ans += res[pos.first][pos.second];
        }
        else {
            break;
        }
    }
    pos = make_pair(r, c);
    while (true) {
        pos.first--;
        pos.second++;
        if (pos.first >= 0 && pos.second >= 0 && pos.first < n && pos.second < m) {
            ans += res[pos.first][pos.second];
        }
        else {
            break;
        }
    }
    pos = make_pair(r, c);
    while (true) {
        pos.first++;
        pos.second++;
        if (pos.first >= 0 && pos.second >= 0 && pos.first < n && pos.second < m) {
            ans += res[pos.first][pos.second];
        }
        else {
            break;
        }
    }
    ans += res[r][c];
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
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> res[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, calc(res, i, j));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
