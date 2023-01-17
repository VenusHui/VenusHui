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

// Codeforces Round #784 (Div. 4) A. 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << "Division ";
        if (n >= 1900) {
            cout << "1" << '\n';
        }
        else if (n >= 1600 && n <= 1899) {
            cout << "2" << '\n';
        }
        else if (n >= 1400 && n <= 1599) {
            cout << "3" << '\n';
        }
        else {
            cout << "4" << '\n';
        }
    }
    
    return 0;
}
