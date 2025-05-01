/**
 * @platform: AcWing
 * @problem: P835
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-18
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const int maxn = 26;
  vector<pair<vector<int>, int>> trie(1, make_pair(vector<int>(maxn), 0));
  function<void(string)> insert = [&](string s) {
    int pos = 0;
    for (auto &e : s) {
      if (trie[pos].first[e - 'a'] == 0) {
        trie[pos].first[e - 'a'] = trie.size();
        trie.push_back(make_pair(vector<int>(maxn), 0));
      }
      pos = trie[pos].first[e - 'a'];
    }
    trie[pos].second++;
  };
  function<int(string)> query = [&](string s) {
    int pos = 0;
    for (auto &e : s) {
      if (trie[pos].first[e - 'a'] == 0)
        return 0;
      pos = trie[pos].first[e - 'a'];
    }
    return trie[pos].second;
  };
  int n;
  cin >> n;
  while (n--) {
    string oper, s;
    cin >> oper >> s;
    if (oper == "I")
      insert(s);
    if (oper == "Q")
      cout << query(s) << '\n';
  }

  return 0;
}
