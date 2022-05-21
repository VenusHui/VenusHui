/***********************************
 *  Codeforces Global Round 20
 *  B. I love AAAB
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
        string s;
        cin >> s;
        int size = s.size();
        if (s[0] == 'B' || s[size - 1] == 'A') {
            cout << "NO" << '\n';
            continue;
        }
        bool ans = true;
        int anum = 0, bnum = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == 'B') {
                bnum++;
            }
            else {
                anum++;
            }
            if (anum < bnum) {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}
