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

// Codeforces Round #774 (Div. 2) A. Square Counting

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n, s;
        cin >> n >> s;
        cout << s / (n * n) << '\n';
    }
    return 0;
}