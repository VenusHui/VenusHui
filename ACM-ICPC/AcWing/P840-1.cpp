/**
 * @platform: AcWing
 * @problem: P840
 * @version: Tutorial Version
 * @author: VenusHui
 * @date: 2023-01-27
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int mod = 5;
  int idx = 0;
  vector<int> hash_list(mod, -1), list, next;
  function<int(int)> hash = [&](int x) { return (x % mod + mod) % mod; };
  function<void(int)> insert = [&](int x) {
    int code = hash(x);
    list.push_back(x), next.push_back(hash_list[code]);
    hash_list[code] = idx++;
  };
  function<bool(int)> query = [&](int x) {
    int code = hash(x);
    for (int i = hash_list[code]; i != -1; i = next[i]) {
      if (list[i] == x)
        return true;
    }
    return false;
  };
  int n;
  cin >> n;
  while (n--) {
    int x;
    string oper;
    cin >> oper >> x;
    if (oper == "I")
      insert(x);
    if (oper == "Q") {
      if (query(x))
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
    }
  }

  return 0;
}
