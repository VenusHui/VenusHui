/*********************************
 *  第20届上海大学程序设计联赛春季赛-D
 *  Writer: VenusHui
 *  Version: Contest Version
 *  Date: 2022-05-08
*********************************/
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
#include <unordered_map>
#include <stack>
#include <set>
#include <numeric>
#include <iomanip>
#include <functional>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n;
    cin >> m >> n;
    if (m == 0) {
        cout << "0" << '\n';
        return 0;
    }
    if (n == 0) {
        cout << "-1" << '\n';
        return 0;
    }
    if (m % n == 0) {
        cout << m / n << '\n';
    }
    else {
        cout << m / n + 1 << '\n';
    }

    return 0;
}
