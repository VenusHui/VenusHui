/**
 * @platform: Nowcoder-PDD
 * @problem: pdd_testC 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-12
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> res(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.find('A') != string::npos) res[i][0] = 1;
        if (s.find('B') != string::npos) res[i][1] = 1;
        if (s.find('C') != string::npos) res[i][2] = 1;
    }
    vector<int> maxp(3), v(3);
    for (int i = 0; i < 3; i++) {
        cin >> maxp[i] >> v[i];
    }
    int maxval = 0x3f3f3f3f, pnum = 0;
    function<void(int, int, vector<int>)> dfs = [&] (int idx, int val, vector<int> status) {
        pnum = max(pnum, idx);
        if (idx == n) {
            maxval = min(maxval, val);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (res[idx][i] && status[i] > 0) {
                status[i]--;
                dfs(idx + 1, val + v[i], status);
                status[i]++;
            }
        }
    };
    vector<int> status = {maxp[0], maxp[1], maxp[2]};
    dfs(0, 0, status);
    if (maxval == 0x3f3f3f3f) {
        cout << "NO" << '\n';
        cout << pnum << '\n';
    }
    else {
        cout << "YES" << '\n';
        cout << maxval << '\n';
    }

    return 0;
}
