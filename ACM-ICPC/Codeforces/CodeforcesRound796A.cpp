#include <iostream>
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
using namespace std;;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    const int maxn = 32;
    while (t--) {
        int x;
        cin >> x;
        vector<int> res(maxn, 0);
        int n = 0;
        while (x) {
            if (x % 2 == 1) {
                res[n] = 1;
            }
            x /= 2;
            n++;
        }
        int y = 0;
        bool flag = false, ok = false;
        for (int i = 0; i < maxn; i++) {
            if (res[i] == 1) {
                if (flag) {
                    ok = true;
                    break;
                }
                else {
                    y += 1 << i;
                    flag = true;
                }
            }
        }
        if (!ok) {
            for (int i = 0; i < maxn; i++) {
                if (res[i] == 0) {
                    y += 1 << i;
                    break;
                }
            }
        }
        cout << y << '\n';
    }
    return 0;
}

