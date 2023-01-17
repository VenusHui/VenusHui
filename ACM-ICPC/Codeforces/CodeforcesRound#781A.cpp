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

// Codeforces Round #781 (Div. 2) A. GCD vs LCM

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            if (n % 4 == 0) {
                cout << n / 4 << " " << n / 4 << " " << n / 4 << " " << n / 4 << '\n';
            }
            else {
                cout << (n - 2) / 2 - 1 << " " << (n - 2) / 2 + 1 << " " << 1 << " " << 1 << '\n';
            }
        }
        else {
            cout << (n - 2) / 2 << " " << (n - 2) / 2 + 1 << " " << 1 << " " << 1 << '\n';
        }

    }

    return 0;
}
