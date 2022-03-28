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

// A-B 数对

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> res(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < n; i++) {
        s.insert(res[i]);
    }
    int maxNum = res[n - 1];
    vector<int> nums(maxNum + 1);
    for (int i = 0; i < n; i++) {
        nums[res[i]]++;
    }
    int ans = 0;
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        if ((*it + c) > maxNum) {
            break;
        }
        int tmp = nums[*it + c];
        if (tmp) {
            ans += tmp * nums[*it];
        }
    }
    cout << ans << '\n';

    return 0;
}
