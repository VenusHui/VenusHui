/**
 * @platform: Codeforces
 * @problem: CodeforcesRound#805C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-07-10
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin, s, '\n');
        int n, k;
        cin >> n >> k;
        vector<int> u(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            cin >> u[i];
            if (mp.find(u[i]) == mp.end()) {
                vector<int> tmp(1, i);
                mp.insert(make_pair(u[i], tmp));
            }
            else {
                mp.find(u[i])->second.push_back(i);
            }
        }
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            bool ans = true;
            if (mp.find(a) == mp.end() || mp.find(b) == mp.end()) {
                ans = false;
            }
            else {
                vector<int> av = mp.find(a)->second;
                vector<int> bv = mp.find(b)->second;
                int asize = av.size(), bsize = bv.size();
                if (av[0] >= bv[bsize - 1]) {
                    ans = false;
                }
            }
            if (ans) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO"  << '\n';
            }
        }
    }

    return 0;
}
