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
#include <stack>
#include <set>
#include <iomanip>
typedef long long ll;
#define endl '\n';
using namespace std;

// 锦标赛

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    sort(res.begin(), res.end());
    int tmp = 1;
    for (int i = 1; i < n; i++) {
        if (res[i] - res[i - 1] > k) {
            tmp = 1;
        }
        else {
            tmp++;
        }
    }
    cout << tmp << '\n';

    return 0;
}
