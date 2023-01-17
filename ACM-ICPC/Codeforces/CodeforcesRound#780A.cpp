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

// Codeforces Round #780 (Div. 3) A. Vasya and Coins

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int sum = a + 2 * b;
        if (a == 0) {
            cout << 1 << '\n';
        }
        else {
            cout << sum + 1 << '\n';
        }
    }

    return 0;
}
