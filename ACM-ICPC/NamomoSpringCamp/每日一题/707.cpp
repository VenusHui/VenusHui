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

// 最长公共子序列

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        b[i] = mp[num];
    }
    vector<int> dp(n + 1, 1);
    int len = 0;
    dp[0] = -1e7;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (dp[mid] < b[i]) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        len = max(len, r + 1);
        dp[r + 1] = b[i];
    }
    cout << len << endl;

    return 0;
}
