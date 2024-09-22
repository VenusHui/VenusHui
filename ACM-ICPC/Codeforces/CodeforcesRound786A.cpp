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
typedef long long ll;
using namespace std;

// Codeforces Round #786 (Div. 3) A. Number Transformation

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y, a = 0, b = 0;
        cin >> x >> y;
        if (x > y || y % x != 0) {
            cout << a << " " << b << '\n';
            continue;
        }
        int tmp = y / x;
        cout << 1 << " " << tmp << '\n';
    }
    
    return 0;
}
