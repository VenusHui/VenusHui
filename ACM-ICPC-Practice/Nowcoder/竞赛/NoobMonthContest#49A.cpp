/************************* 
 *  nowcoder小白月赛49-1
 *  Writer: VenusHui
 *  Date: 2022-05-06
**************************/
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
    int a, b;
    cin >> a >> b;
    vector<int> x(3), y(3), ans(3);
    for (int i = 2; i >= 0; i--) {
        x[i] = a % 10, y[i] = b % 10;
        a /= 10, b /= 10;
    }
    for (int i = 0; i < 3; i++) {
        ans[i] = (x[i] + y[i]) % 3;
    }
    for (int i = 0; i < 3; i++) {
        cout << ans[i];
    }
    cout << '\n';
    
    return 0;
}

