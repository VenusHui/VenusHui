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

// 栈

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    stack<int> s;
    for (int i = 0; i < m; i++)
    {
        int num;
        string oper;
        cin >> oper;
        if (oper == "push")
        {
            cin >> num;
            s.push(num);
        }
        if (oper == "top")
            cout << s.top() << '\n';
        if (oper == "pop")
            s.pop();
    }

    return 0;
}