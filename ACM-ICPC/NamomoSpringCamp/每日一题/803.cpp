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
#include <iomanip>
typedef long long ll;
using namespace std;

// 真假字符串

bool calc(string a, string b, int type) {
    int size = a.size();
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            if (type == 1) {
                b.erase(b.begin() + i);
                b += "$";
                return a == b;
            }
            else if (type == 2) {
                a.erase(a.begin() + i);
                a += "$";
                return a == b;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "0" << '\n';
    }
    bool flag = true;
    int size = a.size();
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            string atmp = a, btmp = b;
            // delete in a, type = 1
            atmp.erase(atmp.begin() + i);
            atmp += "$";
            if (calc(atmp, b, 1)) {
                flag = true;
                break;
            }
            
            // delete in b, type = 2
            btmp.erase(btmp.begin() + i);
            btmp += "$";
            if (calc(a, btmp, 2)) {
                flag = true;
                break;
            }
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "1" << '\n';
    }
    else {
        cout << "0" << '\n';
    }

    return 0;
}
