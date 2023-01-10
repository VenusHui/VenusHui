/**
 * @platform: Acwing
 * @problem: quicksort 
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-09
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void quick_sort(vector<int>& a, int l, int r) {
    if (l == r) {
        return;
    }
    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do {
            i++;
        } while (a[i] < x);
        do {
            j--;
        } while (a[j] > x);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}
