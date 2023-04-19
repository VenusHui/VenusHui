/**
 * @platform: LittleRedBook_Cpp
 * @problem: LittleRedBook_CppB 
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
    const int maxn = 1001;
    int n, addx, tar;
    cin >> n >> addx >> tar;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; i++) {
        pair<int, int> cnt = make_pair(x[i], y[i]);
        while (cnt.first < maxn) {
            tmp.push_back(cnt);
            pair<int, int> mix = make_pair(cnt.first * 2, cnt.second * 2 + addx);
            cnt = mix;
        }
    }
    map<int, int> mp;
    for (auto& e : tmp) mp[e.first] = max(mp[e.first], e.second);
    vector<pair<int, int>> res;
    for (auto& e : mp) res.push_back(e);
    n = res.size();
    vector<int> dp(tar + 1);
    for (int i = 0; i < n; i++) if (res[i].first <= tar) dp[res[i].first] = max(dp[res[i].first], res[i].second);
    for (int j = 1 ; j <= tar; j++) {
        for (int i = 0; i < n; i++) {
            if (j - res[i].first >= 0 && dp[j - res[i].first] != 0) {
                dp[j] = max(dp[j], dp[j - res[i].first] + res[i].second);
            }
        }
    }
    cout << dp[tar] << '\n';

    return 0;
}
