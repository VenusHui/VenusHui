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

// 弗拉德和糖果 II

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    ll sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (mx < res[i]) {
            sum += mx;
            mx = res[i];
        }
        else {
            sum += res[i];
        }
    }
    if (n == 1 && mx == 1 || mx <= sum + 1) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}
