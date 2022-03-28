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

// Codeforces Round #779 (Div. 2) A - Marin and Photoshoot

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && s[i] == '0' && s[i + 1] == '0') {
                ans += 2;
            }
            else if (i + 2 < n && s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0') {
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
