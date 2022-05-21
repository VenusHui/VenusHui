/*********************************
 *  第20届上海大学程序设计联赛春季赛-C
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
    vector<char> res(26);
    for (int i = 0; i < 13; i++) {
        string a, b;
        cin >> a >> b;
        res[a[0] - 'A'] = b[0];
        res[b[0] - 'A'] = a[0];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        for (auto& it : s) {
            it = res[it - 'A'];
        }
        cout << s << " ";
    }

    return 0;
}

