// 饿饿 饭饭
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

int n;                       // 打饭总人数
vector<pair<int, int> > stu; // (饭量，编号)

// 计算完整的num轮打饭需要打多少份饭
ll calc(int num)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(num, stu[i].first); // 若第i人能吃饱，则加上他的饭量，否则加上打饭轮数
    return ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll k, tot = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        stu.push_back(make_pair(tmp, i + 1));
        tot += tmp;
    }
    if (k > tot) // k份饭还打不完
    {
        cout << "-1" << '\n';
        return 0;
    }
    // 二分
    int ll = 0, rr = 1e9;
    while (ll + 1 < rr) // 最后一轮未完成的打饭通过模拟解决，所以这里是ll + 1
    {
        int mid = (rr - ll) / 2 + ll;
        if (calc(mid) <= k)
            ll = mid;
        else
            rr = mid;
    }
    k -= calc(ll); // 此时k为剩余的饭数
    // 模拟最后一轮
    vector<pair<int, int> >::iterator it = stu.begin();
    for (int i = 0; k != 0; i++)
    {
        if (stu[i].first >= ll + 1) // 本轮为ll + 1轮
            k--;
        it++;
    }
    int flag = ll + 1;
    for (int i = 0; i < n; i++)
    {
        if (it->first >= flag)
            cout << it->second << " ";
        it++;
        if (it == stu.end())
        {
            it = stu.begin();
            flag++;
        }
    }
    cout << '\n';

    return 0;
}