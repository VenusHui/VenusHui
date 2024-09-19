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

// Codeforces Round #748 (Div. 3) D1. All are Same

inline int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool inf = true;
        int minval = a[0];

        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[0])
            {
                inf = false;
                break;
            }
            minval = min(minval, a[i]);
        }

        if (inf)
        {
            cout << "-1\n";
            continue;
        }

        sort(a.begin(), a.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = gcd(abs(ans), abs(a[i] - minval));
        cout << abs(ans) << '\n';
    }

    return 0;
}
