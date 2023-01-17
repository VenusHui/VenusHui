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

// Codeforces Round #776 (Div. 3) B. DIV + MOD

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, a;
        cin >> l >> r >> a;
        int tmp = r;
        int mod = r % a;
        if (mod == a - 1)
            cout << r / a + r % a << '\n';
        else
        {
            r = r - mod - 1;
            if (r < l)
                r = tmp;
            cout << r / a + r % a << '\n';
        }
    }

    return 0;
}