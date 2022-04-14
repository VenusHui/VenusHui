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

// 上帝的集合

int n;
const int maxNum = 2e6 + 5;
vector<ll> heap(maxNum);

void up(int p) {
    while (p > 1) {
        if (heap[p] < heap[p / 2]) {
            swap(heap[p], heap[p / 2]);
            p /= 2;
        }
        else {
            break;
        }
    }
}

void down(int p) {
    int s = p * 2;
    while (s <= n) {
        if (s < n && heap[s] > heap[s + 1]) { // 小根堆，左右结点中取较小的
            s++;
        }
        if (heap[s] < heap[p]) {
            swap(heap[s], heap[p]);
            p = s;
            s = p * 2;
        }
        else {
            break;
        }
    }
}

void erase() {
    heap[1] = heap[n--];
    down(1);
}

void insert(ll val) {
    heap[++n] = val;
    up(n);
}

void remove(int k) {
    heap[k] = heap[n--];
    up(k), down(k);
}

ll top() {
    return heap[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            ll num;
            cin >> num;
            insert(num);
        }
        else if (op == 2) {
            ll num;
            cin >> num;
            for (int i = 1; i <= n; i++) {
                heap[i] += num;
            }
        }
        else if (op == 3){
            cout << top() << '\n';
            erase();
        }
    }

    return 0;
}
