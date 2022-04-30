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

// 倒数第n个字符串

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int l, n;
    cin >> l >> n;
    vector<char> ans(l, 'z');
    int pos = l - 1;
    n--;
    while (n) {
        ans[pos] -= (n % 26);
        n /= 26;
        pos--;
    }
    for (int i = 0; i < l; i++) {
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}

