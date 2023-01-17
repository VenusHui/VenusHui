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

// Codeforces Round #786 (Div. 3) D. A-B-C Sort

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
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
        }
        for (int i = n - 1; i >= 1; i -= 2) {
            if (res[i - 1] > res[i]) {
                swap(res[i], res[i - 1]);
            }
        }
        bool ans = true;
        int tmp = res[0];
        for (int i = 1; i < n; i++) {
            if (tmp > res[i]) {
                ans = false;
                break;
            }
            tmp = res[i];
        }
        if (ans) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}
