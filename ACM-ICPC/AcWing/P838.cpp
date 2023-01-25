/**
 * @platform: AcWing
 * @problem: P838 
 * @version: Tutorial Version
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
    int n, m;
    cin >> n >> m;
    int size = n;
    vector<int> heap(size + 1);
    function<void(int)> up = [&] (int x) {
        while (x / 2 != 0 && heap[x / 2] > heap[x]) {
            swap(heap[x / 2], heap[x]);
            x /= 2;
        }
    };
    function<void(int)> down = [&] (int x) {
        int t = x;
        if (x * 2 <= size && heap[x * 2] < heap[t]) t = x * 2;
        if (x * 2 + 1 <= size && heap[x * 2 + 1] < heap[t]) t = x * 2 + 1;
        if (x != t) swap(heap[t], heap[x]), down(t);
    };
    function<void(int)> remove = [&] (int x) {
        heap[x] = heap[size--];
        up(x), down(x);
    };
    for (int i = 1; i <= n; i++) cin >> heap[i];
    for (int i = n / 2; i >= 0; i--) down(i);
    while (m--) {
        cout << heap[1] << " ";
        remove(1);
    }
    cout << '\n';

    return 0;
}
