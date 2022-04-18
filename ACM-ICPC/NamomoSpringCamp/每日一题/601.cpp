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

// BFS练习1

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    int a, q;
    cin >> a >> q;
    const int maxNum = 1e5 + 1;
    vector<int> vis(maxNum, -1);
    int ans = 0, num = a;
    vis[num] = ans;
    queue<pair<int, int>> res;
    res.push(make_pair(num, ans));
    while (!res.empty()) {
        num = res.front().first;
        ans = res.front().second;
        res.pop();
        if (num + 1 >= 0 && num + 1 < maxNum && vis[num + 1] == -1) {
            if (num + 1 < maxNum)
                res.push(make_pair(num + 1, ans + 1));
            vis[num + 1] = ans + 1;
        }
        if (num * 2 >= 0 && num * 2 < maxNum && vis[num * 2] == -1) {
            if (num * 2 < maxNum)
                res.push(make_pair(num * 2, ans + 1));
            vis[num * 2] = ans + 1;
        }
        if (num * 3 >= 0 && num * 3 < maxNum && vis[num * 3] == -1) {
            if (num * 3 < maxNum)
                res.push(make_pair(num * 3, ans + 1));
            vis[num * 3] = ans + 1;
        }
        if (num - 1 >= 0 && num - 1 < maxNum && vis[num - 1] == -1) {
            if (num - 1 >= 0)
                res.push(make_pair(num - 1, ans + 1));
            vis[num - 1] = ans + 1;
        }
    }
    for (int i = 0; i < q; i++) {
        int b;
        cin >> b;
        cout << vis[b] << " ";
    }
    cout << '\n';

    return 0;
}
