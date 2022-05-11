/***********************************
 *  Codeforces Global Round 20
 *  C. Unequal Array
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Date: 2022-05-10
***********************************/
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
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
        }
        int l = -1, r = -1;
        for (int i = 0; i < n - 1; i++) {
            if (res[i] == res[i + 1]) {
                if (l == -1) {
                    l = i;
                }
                r = i;
            }
        }
        if (l == r) {
            cout << "0" << '\n';
        }
        else {
            cout << max(r - l - 1, 1) << '\n';
        }
    }
    
    return 0;
}
