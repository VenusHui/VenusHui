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
#include <unordered_map>
#include <stack>
#include <set>
#include <unordered_set>
#include <iomanip>
typedef long long ll;
#define endl '\n';
using namespace std;

// 跳跳

inline int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > res(n);
    for (int i = 0; i < n; i++)
        cin >> res[i].first >> res[i].second;
    set<pair<int, int> > ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int x = res[j].first - res[i].first;
                int y = res[j].second - res[i].second;
                int tmp = gcd(abs(x), abs(y));
                if (tmp < 0)
                    tmp *= -1;
                ans.insert(make_pair(x / tmp, y / tmp));
            }
        }
    }
    cout << ans.size() << endl;

    return 0;
}