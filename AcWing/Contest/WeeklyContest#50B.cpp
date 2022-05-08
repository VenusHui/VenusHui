/*********************************
 *  AcWing Weekly#50-B
 *  Writer: VenusHui
 *  Version: Tuturial Version
 *  Date: 2022-05-07
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
    int n, m;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    cin >> m;
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    int al = -1, ar = 1e9 + 1;
    int bl = -1, br = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        ar = min(ar, a[i].second);
        al = max(al, a[i].first);
    }
    for (int i = 0; i < m; i++) {
        br = min(br, b[i].second);
        bl = max(bl, b[i].first);
    }
    int tmp1 = max(bl - ar, 0), tmp2 = max(al - br, 0);
    cout << max(tmp1, tmp2) << '\n';

    return 0;
}
