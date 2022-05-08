/*********************************
 *  第20届上海大学程序设计联赛春季赛-A
 *  Writer: VenusHui
 *  Version: Contest Version
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

inline bool dfs(vector<int>& trans, vector<bool>& wall, vector<pair<bool, bool>>& visit, pair<int, int> cnt, int end) {
    if (cnt.first < 0 || cnt.first > end) {
        return false;
    }
    if (wall[cnt.first]) {
        return false;
    }
    if (cnt.first == end) {
        return true;
    }
    if (cnt.second == -1) {
        if (visit[cnt.first].first) {
            return false;
        }
        visit[cnt.first].first = true;
        if (trans[cnt.first] == -1) {
            return dfs(trans, wall, visit, make_pair(cnt.first + 1, 1), end) || dfs(trans, wall, visit, make_pair(cnt.first - 1, -1), end);
        }
        else if (trans[cnt.first] == end) {
            return true;
        }
        else {
            return dfs(trans, wall, visit, make_pair(trans[cnt.first] - 1, -1), end);
        }
    }
    else if (cnt.second == 1) {
        if (visit[cnt.first].second) {
            return false;
        }
        visit[cnt.first].second = true;
        if (trans[cnt.first] == -1) {
            return dfs(trans, wall, visit, make_pair(cnt.first + 1, 1), end) || dfs(trans, wall, visit, make_pair(cnt.first - 1, -1), end);
        }
        else if (trans[cnt.first] == end) {
            return true;
        }
        else {
            return dfs(trans, wall, visit, make_pair(trans[cnt.first] + 1, 1), end);
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 1001;
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> trans(maxn, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        trans[a] = b;
        trans[b] = a;
    }
    vector<bool> wall(maxn, false);
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        wall[num] = true;
    }
    vector<pair<bool, bool>> visit(n + 1, make_pair(false, false));
    if (dfs(trans, wall, visit, make_pair(0, 1), n)) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}

