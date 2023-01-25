/**
 * @platform: AcWing
 * @problem: P839 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-25
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int maxn = 100010;
    int size = 0, idx = 0;
    // ph[k] 第 k 个插入点在堆中的下标，hp[k] 堆中下标为 k 数的插入次序（ph数组中的下标）
    vector<int> heap(maxn), ph(maxn), hp(maxn);
    function<void(int, int)> heap_swap = [&] (int x, int y) {
        swap(ph[hp[x]], ph[hp[y]]);
        swap(hp[x], hp[y]);
        swap(heap[x], heap[y]);
    };
    function<void(int)> up = [&] (int x) {
        while (x / 2 != 0 && heap[x] < heap[x / 2]) {
            heap_swap(x, x / 2);
            x /= 2;
        }
    };
    function<void(int)> down = [&] (int x) {
        int t = x;
        if (x * 2 <= size && heap[x * 2] < heap[t]) t = x * 2;
        if (x * 2 + 1 <= size && heap[x * 2 + 1] < heap[t]) t = x * 2 + 1;
        if (x != t) heap_swap(x, t), down(t);
    };
    function<void(int)> insert = [&] (int x) {
        idx++, size++;
        ph[idx] = size; hp[size] = idx;
        heap[size] = x;
        up(size);
    };
    function<void(int)> remove = [&] (int x) {
        heap_swap(x, size--);
        up(x), down(x);
    };
    function<void(int, int)> modify = [&] (int k, int x) {
        heap[k] = x;
        up(k), down(k);
    };
    int n;
    cin >> n;
    while (n--) {
        string oper;
        cin >> oper;
        if (oper == "I") {
            int x;
            cin >> x;
            insert(x);
        }
        if (oper == "PM") cout << heap[1] << '\n';
        if (oper == "DM") remove(1);
        if (oper == "D") {
            int k;
            cin >> k;
            remove(ph[k]);
        }
        if (oper == "C") {
            int k, x;
            cin >> k >> x;
            modify(ph[k], x);
        }
    }

    return 0;
}
