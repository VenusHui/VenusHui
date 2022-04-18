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
#include <stack>
#include <set>
#include <iomanip>
typedef long long ll;
using namespace std;

// Codeforces Round #781 (Div. 2) B. Array Cloning Technique

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(res[i]) == mp.end()) {
                mp.insert(make_pair(res[i], 1));
            }
            else {
                mp.find(res[i])->second++;
            }
        }
        int cnt = 0;
        map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            cnt = max(cnt, it->second);
        }
        while (cnt < n) {
            ans += (1 + cnt);
            cnt *= 2;
        }
        ans -= (cnt - n);
        cout << ans << '\n';
    }

    return 0;
}
