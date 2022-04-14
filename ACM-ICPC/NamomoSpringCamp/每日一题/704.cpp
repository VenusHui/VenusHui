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

// 子串的循环挪动

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, l, r, k;
    string s, tmp;
    cin >> s >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        int size = r - l + 1; 
        vector<char> res(size);
        for (int j = 0; j < size; j++) {
            res[(j + k) % size] = s[l + j - 1];
        }
        for (int j = 0; j < size; j++) {
            s[j + l - 1] = res[j];
        }
    }
    cout << s << '\n';
    
    return 0;
}
