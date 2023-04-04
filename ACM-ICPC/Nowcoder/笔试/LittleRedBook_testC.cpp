/**
 * @platform: Little Red Book
 * @problem: LittleRedBook_testC 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-26
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    vector<pair<int, int>> opers(m);
    for (int i = 0; i < m; i++) cin >> opers[i].first;
    for (int i = 0; i < m; i++) cin >> opers[i].second;
    string s;
    cin >> s;
    vector<ll> params(m);
    for (int i = 0; i < m; i++) cin >> params[i];
    auto calc1 = [&] (int l, int r, ll x) {
        for (int i = l; i <= r; i++) {
            a[i] = a[i] | x;
        }
    };
    auto calc2 = [&] (int l, int r, ll x) {
        for (int i = l; i <= r; i++) {
            a[i] = a[i] & x;
        }
    };
    auto calc3 = [&] (int l, int r, ll x) {
        for (int i = l; i <= r; i++) {
            a[i] = x;
        }
    };
    for (int i = 0; i < m; i++) {
        if (s[i] == '|') {
            calc1(opers[i].first - 1, opers[i].second - 1, params[i]);
        }
        else if (s[i] == '&') {
            calc2(opers[i].first - 1, opers[i].second - 1, params[i]);
        }
        else if (s[i] == '=') {
            calc3(opers[i].first - 1, opers[i].second - 1, params[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}
