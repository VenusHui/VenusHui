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

// P3374 【模板】树状数组 1

int n, m;
vector<int> tmp(500001);
vector<int> res(2000001);

inline void buildTree(int k, int l, int r) {
    if (l == r) {
        res[k] = tmp[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(k + k, l, mid);
    buildTree(k + k + 1, mid + 1, r);
    res[k] = res[k + k] + res[k + k + 1];
}

inline void add(int k, int l, int r, int x, int y) {
    res[k] += y;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        add(k + k, l, mid, x, y);
    }
    else {
        add(k + k + 1, mid + 1, r, x, y);
    }
}

inline int calc(int k, int l, int r, int s, int t) {
    if (l == s && r == t) {
        return res[k];
    }
    int mid = (l + r) >> 1;
    if (t <= mid) {
        return calc(k + k, l, mid, s, t);
    }
    else {
        if (s > mid) {
            return calc(k + k + 1, mid + 1, r, s, t);
        }
        else {
            return calc(k + k, l, mid, s, mid) + calc(k + k + 1, mid + 1, r, mid + 1, t);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> tmp[i];
    
    // 建树
    buildTree(1, 1, n);
    for (int i = 0; i < m; i++) {
        int oper, x, y;
        cin >> oper >> x >> y;
        if (oper == 1) {
            add(1, 1, n, x, y);
        }
        else {
            cout << calc(1, 1, n, x, y) << '\n';
        }
    }

    return 0;
}