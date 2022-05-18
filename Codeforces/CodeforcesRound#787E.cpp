/*********************************
 *  Codeforces Round #787 (Div. 3) 
 *  E. Replace With the Previous, Minimize
 *  Writer: VenusHui
 *  Version: Tuturial Version
 *  Date: 2022-05-07
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int ch = 'a'; ch <= 'z'; ch++) {
            char flag = 'a' - 1;
            bool tag = true;
            for (int i = 0; i < n; i++) {
                if (s[i] > ch) {
                    if (tag && s[i] - ch <= k) {
                        flag = max(flag, s[i]);
                    }
                    else {
                        tag = false;
                    }
                }
            }
            if (flag != 'a' - 1) {
                for (int i = 0; i < n; i++) {
                    if (s[i] > ch && s[i] <= flag) {
                        s[i] = ch;
                    }
                }
                k -= max(flag - ch, 0);
            }
        }
        cout << s << '\n';
    }
    
    return 0;
}
