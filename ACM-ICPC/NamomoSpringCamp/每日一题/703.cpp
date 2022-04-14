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

// 简单的异或问题

// 异或和：n个数连续进行异或的结果

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    ll res = 1;
    res <<= m;
    if (m == 1 && n == 0) {
        cout << 1 << endl;
    }
    else if (m == 1 && n == 1) {
        cout << 2 << endl;
    }
    else {
        cout << (1LL) * (res - min(n, 1LL)) << endl;
    }
    return 0;
}
