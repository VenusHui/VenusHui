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

// 饿饿 饭饭之暑假大狂欢

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<vector<int> > res;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> tmp(n);
        for (int j = 0; j < n; j++) {
            cin >> tmp[j];
        }
        res.push_back(tmp);
    }
    for (int i = 0; i < t; i++) {
        int fsize = res[i].size();
        set<int> comp;
        for (int j = 0; j < fsize; j++) {
            comp.insert(res[i][j]);
        }
        bool flag = true;
        for (int j = 0; j < t; j++) {
            if (j == i) {
                continue;
            }
            bool win = false;
            int ssize = res[j].size();
            for (int k = 0; k < ssize; k++) {
                if (comp.find(res[j][k]) == comp.end()) {
                    win = true;
                    break;
                }
            }
            if (!win) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}