/***********************************
 *  Codeforces Round #790 (Div. 4)
 *  A. Lucky?
 *  Writer: VenusHui    
 *  Version: Contest Version
 *  Date: 2022-05-11
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
        string s;
        cin >> s;
        if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
