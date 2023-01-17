/**
 * @platform: AcWing
 * @problem: WeeklyContest#86B 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-14
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int rnum = n, cnum = n;
    vector<ll> ans;
    vector<bool> row(n, false), col(n, false);
    ll num = 1LL * n * n;
    while (m--) {
        int x, y, flag = 0;
        cin >> x >> y;
        if (!row[x - 1]) row[x - 1] = true, num -= cnum, flag += 1;
        if (!col[y - 1]) col[y - 1] = true, num -= rnum, flag += 2;
        if (flag == 3) num++;
        ans.push_back(num);
        if (flag == 1) rnum--;
        if (flag == 2) cnum--;
        if (flag == 3) rnum--, cnum--;
    }
    for (auto& e : ans) cout << e << " ";
    cout << '\n';

    return 0;
}
