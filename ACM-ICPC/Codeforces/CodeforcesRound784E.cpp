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
typedef long long ll;
using namespace std;

// Codeforces Round #784 (Div. 4) E

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> res(n);
        map<string, ll> mp;

        // second bit
        for (int i = 0; i < n; i++) {
            cin >> res[i];
            if (mp.find(res[i]) == mp.end()) {
                mp.insert(make_pair(res[i], 1));
            }
            else {
                mp.find(res[i])->second++;
            }
        }
        ll ans = 0;
        vector<vector<ll> > num(11);
        for (auto m : mp) {
            num[m.first[0] - 'a'].push_back(m.second);
        }
        for (int i = 0; i < 11; i++) {
            int size = num[i].size();
            for (int j = 0; j < size - 1; j++) {
                for (int k = j + 1; k < size; k++) {
                    ans += (num[i][j] * num[i][k]);
                }
            }
        }

        // first bit
        mp.clear();
        for (int i = 0; i < 11; i++) {
            num[i].clear();
        }
        for (int i = 0; i < n; i++) {
            swap(res[i][0], res[i][1]);
            if (mp.find(res[i]) == mp.end()) {
                mp.insert(make_pair(res[i], 1));
            }
            else {
                mp.find(res[i])->second++;
            }
        }
        for (auto m : mp) {
            num[m.first[0] - 'a'].push_back(m.second);
        }
        for (int i = 0; i < 11; i++) {
            int size = num[i].size();
            for (int j = 0; j < size - 1; j++) {
                for (int k = j + 1; k < size; k++) {
                    ans += (num[i][j] * num[i][k]);
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
