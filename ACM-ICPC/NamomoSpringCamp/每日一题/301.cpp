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

// 出栈序列判断

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    stack<int> s;
    s.push(0);
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (seq[pos] > i + 1)
        {
            cout << "push " << i + 1 << '\n';
            s.push(i + 1);
        }
        else if (seq[pos] == i + 1)
        {
            cout << "push " << i + 1 << '\n';
            cout << "pop" << '\n';
            pos++;
        }
        else if (seq[pos] < i + 1)
        {
            s.pop();
            cout << "pop" << '\n';
            pos++;
            i--;
        }
    }
    int size = s.size();
    while (size > 1)
    {
        s.pop();
        cout << "pop" << '\n';
        size--;
    }

    return 0;
}