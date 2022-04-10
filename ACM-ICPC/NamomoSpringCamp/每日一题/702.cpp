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

// 三回文序列

int n;

int change(vector<int>v, int ans, vector<int>nums)
{
    int l = 0, r = n - 1, cnt = 0, res = nums[ans];
    while (l < r) {
        while (l < r && v[l] != ans) {
            nums[v[l]]--;
            l++;
        }
        while (l < r && v[r] != ans) {
            nums[v[r]]--;
            r--;
        }
        cnt += min(nums[ans], 2);
        nums[ans] -= 2;
        l++, r--;
        for (int i = 1; i <= 26; i++) {
            res = max(res, cnt + nums[i]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int>v(n),nums(27);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            nums[v[i]]++;
        }
        int res = 0;
        for (int i = 1; i < 27; i++)
        {
            if (nums[i] != 0)
                res = max(res, change(v, i,nums));
        }
        cout << res << endl;
    }
    return 0;
}
