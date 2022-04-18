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

// 整除光棍

vector<int> div(vector<int>& res, int num) {
    int size = res.size();
    int tmp = 0;
    vector<int> ans;
    vector<int> f;
    for (int i = 0; i < size; i++) {
        tmp = tmp * 10 + res[i];
        ans.push_back(tmp / num);
        tmp %= num;
    }
    if (tmp) {
        return f;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x;
    cin >> x;
    int size = 1e6 + 1, len = 0, asize = 0;
    vector<int> ans;
    for (int i = 1; i <= size; i++) {
        vector<int> res(i, 1);
        ans = div(res, x);
        asize = ans.size();
        if (ans.size() != 0) {
            len = i;
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < asize; i++) {
        cout << ans[i];
    }
    cout << " " << len << '\n';
    
    return 0;
}
