/**
 * @platform: LittleRedBook_Cpp
 * @problem: LittleRedBook_CppC 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-04-09
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
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    string col;
    cin >> col;
    int m;
    cin >> m;
    int qnum = 0;
    vector<pair<int, int>> oper(m);
    for (int i = 0; i < m; i++) cin >> oper[i].first;
    for (int i = 0; i < m; i++) {
        cin >> oper[i].second;
        if (oper[i].second == 0) qnum++;
    }
    cout << qnum << " ";
    sort(oper.begin(), oper.end());
    vector<bool> pocket(n, false);
    auto change = [&] (int delta) {
        for (int i = 0; i < n; i++) {
            if (pocket[i]) {
                if (col[i] == 'R') nums[i] += delta;
                if (col[i] == 'B') nums[i] -= delta;
            }
        }
    };
    auto calc = [&] () {
        int ans = 0;
        for (int i = 0; i < n; i++) if (pocket[i]) ans += nums[i];
        return ans;
    };
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        change(oper[i].first - cnt), cnt = oper[i].first;
        if (oper[i].second == 0) cout << calc() << ' ';
        else if (oper[i].second > 0) pocket[oper[i].second - 1] = true;
        else if (oper[i].second < 0) pocket[-1 * oper[i].second - 1] = false;
    }
    cout << '\n';

    return 0;
}
