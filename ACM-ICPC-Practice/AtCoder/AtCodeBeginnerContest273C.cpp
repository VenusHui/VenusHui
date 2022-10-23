/**
 * @platform: AtCoder
 * @problem: AtCodeBeginnerContest273C 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2022-10-15
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    vector<int> res;
    int tmp = 0;
    map<int, int>::reverse_iterator it;
    for (it = mp.rbegin(); it != mp.rend(); it++) {
        for (int j = 0; j < it->second; j++) {
            res.push_back(tmp);
        }
        tmp++;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[res[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
