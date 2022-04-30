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

// Codeforces Round #785 (Div. 2) A. Subtle Substring Subtraction

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int size = s.size();
        ll a = 0, b = 0;
        if (size % 2 == 0) {
            cout << "Alice ";
            for (int i = 0; i < size; i++) {
                a += s[i] - 'a' + 1;
            }
            cout << a << '\n';
        }
        else {
            ll atmp1 = 0, atmp2 = 0;
            for (int i = 0; i < size - 1; i++) {
                atmp1 += s[i] - 'a' + 1;
            }
            for (int i = 1; i < size; i++) {
                atmp2 += s[i] - 'a' + 1;
            }
            a = max(atmp1, atmp2);
            if (atmp1 >= atmp2) {
                b = s[size - 1] - 'a' + 1;
                if (a > b) {
                    cout << "Alice " << a - b << '\n';
                }
                else {
                    cout << "Bob " << b << '\n';
                }
            }
            else {
                b = s[0] - 'a' + 1;
                if (a > b) {
                    cout << "Alice " << a - b << '\n';
                }
                else {
                    cout << "Bob " << b << '\n';
                }
            }
        }
    }
    return 0;
}
