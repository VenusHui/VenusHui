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
ll num[200005], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);
    for (int i = 0; i < N; i++)
    {
        ans = ans + (upper_bound(num, num + N, num[i] - C) - num) - (lower_bound(num, num + N, num[i] - C) - num);
    }
    cout << ans << endl;

    return 0;
}