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

// Codeforces Round #772 (Div. 2) A. Min Or Sum
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> nums(n);
        const int size = 31;
        vector<bool> bits(size);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        for (int i = 0; i < n; i++)
        {
            int pos = 0;
            while (nums[i] > 0)
            {
                if (bits[pos] == false)
                    bits[pos] = nums[i] % 2;
                nums[i] /= 2;
                pos++;
            }
        }
        ll ans = 0;
        for (int i = 0; i < size; i++)
            ans += bits[i] * static_cast<ll>(1 << i);
        cout << ans << '\n';
    }

    return 0;
}