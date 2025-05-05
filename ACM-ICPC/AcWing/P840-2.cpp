/**
 * @platform: AcWing
 * @problem: P840-2
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
  const int mod = 200003, mark = 0x3f3f3f3f;
  vector<int> hash_list(mod, mark);
  function<int(int)> hash = [&](int x) { return (x % mod + mod) % mod; };
  function<int(int)> find = [&](int x) {
    int code = hash(x);
    while (hash_list[code] != mark && hash_list[code] != x) {
      code++;
      if (code == mod)
        code = 0;
    }
    return code;
  };
  function<void(int)> insert = [&](int x) {
    int pos = find(x);
    hash_list[pos] = x;
  };
  function<bool(int)> query = [&](int x) {
    int pos = find(x);
    return hash_list[pos] != mark;
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
