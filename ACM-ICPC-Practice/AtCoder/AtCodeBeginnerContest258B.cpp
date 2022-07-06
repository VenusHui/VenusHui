/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest258B 
 * @version: Contets Version
 * @author: VenusHui
 * @date: 2022-07-02
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
    vector<string> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    vector<char> ans(n);
    for (int l = 0; l < n; l++) {
        for (int r = 0; r < n; r++) {
            // x
            vector<char> tmp(n);
            pair<int, int> s = make_pair(l, r);
            for (int i = 0; i < n; i++) {
                tmp[i] = res[s.first][s.second];
                s.first = (s.first + 1 + n) % n;
            }
            ans = max(ans, tmp);
            s = make_pair(l, r);
            for (int i = 0; i < n; i++) {
                tmp[i] = res[s.first][s.second];
                s.first = (s.first - 1 + n) % n;
            }
            ans = max(ans, tmp);
            
            // y
            s = make_pair(l, r);
            for (int i = 0; i < n; i++) {
                tmp[i] = res[s.first][s.second];
                s.second = (s.second + 1 + n) % n;
            }
            ans = max(ans, tmp);
            s = make_pair(l, r);
            for (int i = 0; i < n; i++) {
                tmp[i] = res[s.first][s.second];
                s.second = (s.second - 1 + n) % n;
            }
            ans = max(ans, tmp);

            // xy
            s = make_pair(l, r);
            for (int i = 0; i < n; i++) {
                tmp[i] = res[s.first][s.second];
                s.first = (s.first + 1 + n) % n;
                s.second = (s.second + 1 + n) % n;
            }
            ans = max(ans, tmp);
            s = make_pair(l, r);
            for (int i = 0; i < n; i++) {
                tmp[i] = res[s.first][s.second];
                s.first = (s.first - 1 + n) % n;
                s.second = (s.second - 1 + n) % n;
            }
            ans = max(ans, tmp);

            // yx
            s = make_pair(l, r);
            for (int i = 0; i < n; i++) {
                tmp[i] = res[s.first][s.second];
                s.first = (s.first - 1 + n) % n;
                s.second = (s.second + 1 + n) % n;
            }
            ans = max(ans, tmp);
            s = make_pair(l, r);
            for (int i = 0; i < n; i++) {
                tmp[i] = res[s.first][s.second];
                s.first = (s.first + 1 + n) % n;
                s.second = (s.second - 1 + n) % n;
            }
            ans = max(ans, tmp);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
