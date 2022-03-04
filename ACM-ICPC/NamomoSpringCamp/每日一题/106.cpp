// 订单编号
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
#include <unordered_map>
#include <stack>
#include <set>
#include <unordered_set>
#include <iomanip>
typedef long long ll;
using namespace std;

int n;
set<pair<int, int>> numSet;

void insert(int l, int r)
{
    if (l > r)
        return;
    else
        numSet.insert(make_pair(r, l));
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    numSet.insert(make_pair(2e9, 1));
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        set<pair<int, int>>::iterator it = numSet.lower_bound(make_pair(tmp, 0));
        if (it->second <= tmp)
        {
            cout << tmp << " ";
            insert(it->second, tmp - 1);
            insert(tmp + 1, it->first);
            numSet.erase(it);
        }
        else
        {
            cout << it->second << " ";
            insert(it->second + 1, it->first);
            numSet.erase(it);
        }
    }
    cout << '\n';

    return 0;
}