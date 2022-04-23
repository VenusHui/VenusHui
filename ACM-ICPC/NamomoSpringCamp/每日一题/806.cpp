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

// 互质

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int size, m;
    cin >> size >> m;
    set<int> s;
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        for (int j = 2; j <= num / j; j++) {
            while (num % j == 0) {
                s.insert(j);
                num /= j;
            }
        }
        if (num > 1) {
            s.insert(num);
        }
    }
    vector<bool> ans(m + 1, true);
    ans[0] = false;
    for (auto i : s) {
        if (ans[i]) {
            for (int j = i; j <= m; j += i) {
                ans[j] = false;
            }
        }
    }
    int len = 0;
    for (int i = 1; i <= m; i++) {
        if (ans[i]) {
            len++;
        }
    }
    cout << len << '\n';
    for (int i = 1; i <= m; i++) {
        if (ans[i]) {
            cout << i << '\n';
        }
    }
    
    return 0;
}
