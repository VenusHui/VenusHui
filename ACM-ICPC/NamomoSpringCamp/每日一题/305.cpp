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

// 删删

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        set<int> delim;
        int ans = n + 1;
        for (int i = 0; i < n; i++)
        {
            if (delim.find(s[i]) == delim.end())
            {
                bool flag = true;
                int tmp = 0;
                delim.insert(s[i]);
                int l = 0, r = n - 1;
                while (l < r)
                {
                    if (s[l] == s[r])
                    {
                        l++;
                        r--;
                    }
                    else if (s[l] == s[i])
                    {
                        l++;
                        tmp++;
                    }
                    else if (s[r] == s[i])
                    {
                        r--;
                        tmp++;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ans = min(ans, tmp);
            }
        }
        if (ans > n)
            cout << "-1" << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}