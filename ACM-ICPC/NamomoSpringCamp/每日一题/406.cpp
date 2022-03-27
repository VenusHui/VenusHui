#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
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
#define endl '\n';
using namespace std;

// 循环子串

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        string r = s;
        reverse(r.begin(), r.end());
        int start = 0;
        bool flag = false;
        while (start != n)
        {
            flag = false;
            for (int i = start, j = 0; i < n && j < n; i++, j++) {
                flag = true;
                if (s[i] != r[j]) {
                    flag = false;
                    break;
                }
                if (i == n - 1) {
                    i = -1;
                }
            }
            start++;
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}