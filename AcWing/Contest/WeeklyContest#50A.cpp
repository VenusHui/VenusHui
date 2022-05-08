/*********************************
 *  AcWing Weekly#50-A
 *  Writer: VenusHui
 *  Version: Tuturial Version
 *  Date: 2022-05-07
*********************************/
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
#include <functional>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 2e5 + 1;
    int n;
    cin >> n;
    vector<bool> ans(maxn);
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        ans[num] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!ans[i]) {
            cout << i << " ";
        }
    }
    cout << '\n';
    
    return 0;
}
