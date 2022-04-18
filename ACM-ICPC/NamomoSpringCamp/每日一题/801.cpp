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
#include <iomanip>
typedef long long ll;
using namespace std;

// 喵喵序列 - 暴力

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
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = 0;
        for (int j = 0; j < i; j++) {
            if (res[j] < res[i]) {
                l++;
            }
        }
        int r = 0;
        for (int j = i + 1; j < n; j++) {
            if (res[j] > res[i]) {
                r++;
            }
        }
        ans += (l * r);
    }
    cout << ans << '\n';

    return 0;
}
