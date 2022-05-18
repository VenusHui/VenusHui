/***********************************
 *  Codeforces Round #791 (Div. 2)
 *  A. AvtoBus
 *  Writer: VenusHui on VScode
 *  Version: Tutorial Version
 *  Date: 2022-05-14
***********************************/
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
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n < 4 || n % 2 == 1) {
            cout << "-1" << '\n';
            continue;
        }
        // min
        if (n % 6 == 0) {
            cout << n / 6 << " ";
        }
        else if (n % 6 == 2) {
            cout << n / 6 + 1 << " ";
        }
        else {
            cout << n / 6 + 1 << " ";
        }

        // max
        if (n % 4 == 0) {
            cout << n / 4 << '\n';
        }
        else {
            cout << n / 4 << '\n';
        }
    }

    return 0;
}
