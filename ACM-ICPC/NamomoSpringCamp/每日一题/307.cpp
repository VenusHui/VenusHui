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

// 饿饿 饭饭2

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        bool flag = true;
        for (int i = 0; i < n; i++) {
            while (nums[i] % 2 == 0 || nums[i] % 3 == 0) {
                if (nums[i] % 2 == 0)
                    nums[i] /= 2;
                if (nums[i] % 3 == 0)
                    nums[i] /= 3;
            }
            if (i > 0 && nums[i] != nums[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}