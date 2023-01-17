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

// Codeforces Round #771 (Div. 2) A.Reverse
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        // find l and r
        // problem: if we can find l, whether there must be an r
        int n, left = 1, right = 1;
        cin >> n;
        vector<int> permutation(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> permutation[i];
        for (int i = 1; i <= n; i++)
        {
            if (permutation[i] != i)
            {
                left = i;
                break;
            }
        }
        for (int i = left + 1; i <= n; i++)
        {
            if (permutation[i] == left)
            {
                right = i;
                break;
            }
        }

        // reverse the permutation
        while (left < right)
        {
            swap(permutation[left], permutation[right]);
            left++, right--;
        }
        for (int i = 1; i <= n; i++)
            cout << permutation[i] << " ";
        cout << endl;
    }

    return 0;
}