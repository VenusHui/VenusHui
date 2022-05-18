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

// Codeforces Round #780 (Div. 3) B. Vlad and Candies

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
        }
        if (n == 1) {
            if (res[0] == 1) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
            continue;
        }
        sort(res.begin(), res.end());
        if (res[n - 1] - res[n - 2] > 1) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}