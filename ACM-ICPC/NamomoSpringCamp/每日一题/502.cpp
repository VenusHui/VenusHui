#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
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
#define endl '\n';
using namespace std;

// 数组操作

int main() {
    ios::sync_with_stdio(false);
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
        int ans = 0;
        int pos = n - 1, len = 0;
        int num = res[pos];
        while (pos >= 0) {
            while (res[pos] == num) {
                len++;
                pos--;
                if (pos == 0) {
                    break;
                }
            }
            bool flag = true;
            for (int i = pos; i >= max(pos - len, 0); i--) {
                if (num != res[i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                ans++;
            }
            pos = pos - len;
            len *= 2;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
