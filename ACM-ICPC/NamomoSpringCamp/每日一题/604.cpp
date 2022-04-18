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

// 碰撞2

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int> > res(n);
    map<int, vector<pair<int, int> > > mp;
    for (int i = 0; i < n; i++) {
        cin >> res[i].first >> res[i].second;
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (mp.find(res[i].second) == mp.end()) {
            vector<pair<int, int> > tmp;
            tmp.push_back(make_pair(res[i].first, s[i]));
            mp.insert(make_pair(res[i].second, tmp));
        }
        else {
            mp.at(res[i].second).push_back(make_pair(res[i].first, s[i]));
        }
    }
    map<int, vector<pair<int, int> > >::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        int size = it->second.size(), l = 0, r = 1e9 + 1;
        for (int i = 0; i < size; i++) {
            if (it->second[i].second == 'L') {
                l = max(l, it->second[i].first);
            }
            else {
                r = min(r, it->second[i].first);
            }
        }
        if (l >= r) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    
    return 0;
}
