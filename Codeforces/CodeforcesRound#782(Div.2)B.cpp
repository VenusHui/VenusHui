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
#include <iomanip>
typedef long long ll;
using namespace std;

// Codeforces Round #782 (Div. 2) B. Bit Flipping

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
        vector<int> ans(n);
        // confirm the left is all 1
        int opos = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                opos = i;
                break;
            }
        }
        if (k % 2 == 1) {
            k--;
            ans[opos]++;
            for (int i = 0; i < n; i++) {
                if (i != opos)
                    s[i] = char(int(s[i] == '0') + '0');
            }
        }

        for (int i = 0; i < n - 1 && k > 0; i++) {
            if (s[i] == '0') {
                int j;
                for (j = i + 1; j < n; j++) {
                    if (s[j] == '0') {
                        break;
                    }
                }
                if (j < n) {
                    s[i] = '1', s[j] = '1';
                    ans[i]++, ans[j]++;
                }
                else {
                    s[i] = '1', s[n - 1] = '0';
                    ans[i]++, ans[n - 1]++;
                }
                k -= 2;
            }
        }
        if (k > 0) {
            ans[n - 1] += k;
        }
        cout << s << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
