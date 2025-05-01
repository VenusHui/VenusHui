/**
 * @platform: Acwing
 * @problem: P787
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-09
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void merge_sort(vector<int> &a, int l, int r) {
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  merge_sort(a, l, mid);
  merge_sort(a, mid + 1, r);
  vector<int> tmp;
  int k = 0; // 目前集合中已排序数的个数
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) {
      tmp.push_back(a[i++]);
    } else {
      tmp.push_back(a[j++]);
    }
  }
  while (i <= mid) {
    tmp.push_back(a[i++]);
  }
  while (j <= r) {
    tmp.push_back(a[j++]);
  }
  for (i = l, j = 0; i <= r; i++, j++) {
    a[i] = tmp[j];
  }
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
  merge_sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';

  return 0;
}
