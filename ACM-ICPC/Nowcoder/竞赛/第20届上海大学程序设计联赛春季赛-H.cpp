/*********************************
 *  第20届上海大学程序设计联赛春季赛-H
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
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (flag) {
                    flag = false;
                    ans++;
                }
            }
            else {
                flag = true;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
