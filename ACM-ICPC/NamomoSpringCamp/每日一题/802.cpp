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

// 漂亮数

// 高精度加法板子
string add(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    int n = max(n1, n2);
    string res(n + 1, '0');
    for (int i = n1; i < n; i++) {
        s1.insert(0, "0");
    }
    for (int i = n2; i < n; i++) {
        s2.insert(0, "0");
    }
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = 0;
        if (s1[i])
            x += s1[i] - '0';
        else
            x += 0;
        if (s2[i])
            x += s2[i] - '0';
        else
            x += 0;
        x += r;
        if (x >= 10) {
            x -= 10;
            r = 1;
        }
        else
            r = 0;
        res[i + 1] = x + '0';
    }
    res[0] = r + '0';
    for (int i = 0; i <= n; i++) {
        if (res[i] != '0')
            return res.substr(i);
    }
    return "0";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s, tmp, ans;
    cin >> s;
    for (int i = 0; i < k; i++) {
        tmp += s[i];
    }
    for (int i = 0; i < n / k; i++) {
        ans += tmp;
    }
    for (int i = 0; i < n % k; i++) {
        ans += tmp[i];
    }
    if (ans >= s) {
        cout << n << '\n';
        cout << ans << '\n';
    }
    else {
        tmp = add(tmp, "1");
        ans.clear();
        for (int i = 0; i < n / k; i++) {
            ans += tmp;
        }
        for (int i = 0; i < n % k; i++) {
            ans += tmp[i];
        }
        cout << n << '\n';
        cout << ans << '\n';
    }

    return 0;
}
