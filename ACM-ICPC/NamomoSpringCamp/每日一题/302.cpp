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
#include <unordered_map>
#include <stack>
#include <set>
#include <unordered_set>
#include <iomanip>
typedef long long ll;
#define endl '\n';
using namespace std;

// 序列维护

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    vector<int> seq;
    for (int i = 0; i < m; i++)
    {
        int x, y, k;
        string oper;
        cin >> oper;
        vector<int>::iterator it = seq.begin();
        if (oper == "insert")
        {
            cin >> x >> y;
            while (x--)
                it++;
            seq.insert(it, y);
        }
        else if (oper == "delete")
        {
            cin >> x;
            x--;
            while (x--)
                it++;
            seq.erase(it);
        }
        else if (oper == "query")
        {
            cin >> k;
            k--;
            while (k--)
                it++;
            cout << *it << '\n';
        }
    }

    return 0;
}