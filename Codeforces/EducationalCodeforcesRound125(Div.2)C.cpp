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

// Educational Codeforces Round 125 (Div. 2) C. Bracket Sequence Deletion

int length;
int n, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string str;
        cin >> str;
        ans = 0, length = n;
        int ll = 0;
        while (ll <= n)
        {
            int reflag = 0, paflag = 0;
            // regular
            stack<char> s;
            int tmp = 0;
            for (int i = ll; i < n; i++)
            {
                if (str[i] == '(')
                {
                    s.push('(');
                    tmp++;
                }
                else
                {
                    if (!s.empty())
                    {
                        s.pop();
                        tmp++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (s.empty())
                    break;
            }
            if (s.empty())
                reflag = tmp;

            // palindrome
            int len;
            for (len = 2; len <= n - ll; len++)
            {
                bool flag = true;
                int l = ll, r = ll + len - 1;
                while (l <= r)
                {
                    if (str[l] == str[r])
                    {
                        l++;
                        r--;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    paflag = len;
                    break;
                }
            }

            // all
            if (reflag || paflag)
            {
                if (reflag == 0)
                {
                    ans++;
                    ll += paflag;
                    continue;
                }
                else if (paflag == 0)
                {
                    ans++;
                    ll += reflag;
                    continue;
                }
                else if (reflag <= paflag)
                {
                    ans++;
                    ll += reflag;
                    continue;
                }
                else
                {
                    ans++;
                    ll += paflag;
                    continue;
                }
            }
            else
            {
                break;
            }
        }

        cout << ans << " " << n - ll << '\n';
    }

    return 0;
}