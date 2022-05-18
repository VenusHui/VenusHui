/***********************************
 *  Codeforces Round #791 (Div. 2)
 *  B. Stone Age Problem (线段树板子)
 *  Writer: VenusHui on VScode
 *  Version: Contest Version
 *  Date: 2022-05-14
 ***********************************/
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
#include <numeric>
#include <iomanip>
typedef long long ll;
using namespace std;

const int maxn = 2e5 + 1;

ll tree[maxn * 4], lz[maxn * 4];
int a[maxn];

void build(int i, int l, int r)
{
    if (l == r)
    {
        tree[i] = a[l];
        return;
    }
    int mid = (l + r) >> 1, k = i << 1;
    build(k, l, mid);
    build(k | 1, mid + 1, r);
    tree[i] = tree[k] + tree[k | 1];
}

void pushdown(int i, int l, int r)
{
    int mid = (l + r) >> 1, k = i << 1;
    tree[k] = lz[i] * (mid - l + 1), tree[k | 1] = lz[i] * (r - mid);
    lz[k] = lz[k | 1] = lz[i];
    lz[i] = 0;
}

void upd(int i, int l, int r, int x, int y, int val)
{
    if (l == x && r == y)
    {
        tree[i] = val * (r - l + 1);
        lz[i] = val;
        return;
    }
    if (lz[i])
        pushdown(i, l, r);
    int mid = (l + r) >> 1, k = i << 1;
    if (y <= mid)
        upd(k, l, mid, x, y, val);
    else if (x > mid)
        upd(k | 1, mid + 1, r, x, y, val);
    else
        upd(k, l, mid, x, mid, val), upd(k | 1, mid + 1, r, mid + 1, y, val);
    tree[i] = tree[k] + tree[k | 1];
}

ll query(int i, int l, int r, int x, int y)
{
    if (l == x && r == y)
    {
        return tree[i];
    }
    if (lz[i])
        pushdown(i, l, r);
    int mid = (l + r) >> 1, k = i << 1;
    if (y <= mid)
        return query(k, l, mid, x, y);
    else if (x > mid)
        return query(k | 1, mid + 1, r, x, y);
    else
        return query(k, l, mid, x, mid) + query(k | 1, mid + 1, r, mid + 1, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index, x;
            cin >> index >> x;
            upd(1, 1, n, index, index, x);
            cout << query(1, 1, n, 1, n) << '\n';
        }
        else
        {
            int x;
            cin >> x;
            upd(1, 1, n, 1, n, x);
            cout << 1LL * n * x << '\n';
        }
    }

    return 0;
}
