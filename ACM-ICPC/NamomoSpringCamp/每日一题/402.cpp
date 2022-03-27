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

// 蒟蒻

int main()
{
    int n;
    cin >> n;
    set<pair<int, int> > sw, st;
    for (int i = 0; i < n; i++)
    {
        int op, w = 0, t = 0;
        cin >> op;
        if (op == 1)
        {
            cin >> w >> t;
            bool flag = true;
            for (set<pair<int, int> >::iterator it = sw.begin(); it != sw.end(); it++)
            {
                if (it->first == w)
                {
                    flag = false;
                    break;
                }
            }
            for (set<pair<int, int> >::iterator it = st.begin(); it != st.end(); it++)
            {
                if (it->first == t)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                sw.insert(make_pair(w, t));
                st.insert(make_pair(t, w));
            }
        }
        if (op == 2)
        {
            int ww = sw.begin()->first;
            int tt = sw.begin()->second;
            sw.erase(sw.begin());
            st.erase(make_pair(tt, ww));
        }
        if (op == 3)
        {
            int ww = st.begin()->second;
            int tt = st.begin()->first;
            st.erase(st.begin());
            sw.erase(make_pair(ww, tt));
        }
    }
    int ans = 0;
    for (set<pair<int, int> >::iterator it = sw.begin(); it != sw.end(); it++)
    {
        ans += it->first;
    }
    cout << ans << '\n';
    return 0;
}
