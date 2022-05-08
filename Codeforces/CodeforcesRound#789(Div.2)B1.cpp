/*********************************
 *  Codeforces Round #789 (Div. 2) B1
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Date: 2022-05-08
*********************************/
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
#include <functional>
typedef long long ll;
using namespace std;

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
        string s;
        cin >> s;
        s += "$";
        int tmp = 1;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[i + 1]) {
                tmp++;
            }
            else {
                res.push_back(tmp);
                tmp = 1;
            }
        }
        int size = res.size(), ans = 0;
        for (int i = 0; i < size - 1; i++) {
            if (res[i] % 2 != 0) {
                res[i]++;
                res[i + 1]++;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
