/**
 * @platform: AcWing
 * @problem: P3302
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-14
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  unordered_map<char, int> mp;
  mp['+'] = 1, mp['-'] = 1, mp['*'] = 2, mp['/'] = 2;
  string s;
  cin >> s;
  stack<int> stk_num;
  stack<char> stk_sym;
  function<void()> calc = [&]() {
    int rvalue = stk_num.top();
    stk_num.pop();
    int lvalue = stk_num.top();
    stk_num.pop();
    char oper = stk_sym.top();
    stk_sym.pop();
    int ans = 0;
    if (oper == '+')
      ans = lvalue + rvalue;
    if (oper == '-')
      ans = lvalue - rvalue;
    if (oper == '*')
      ans = lvalue * rvalue;
    if (oper == '/')
      ans = lvalue / rvalue;
    stk_num.push(ans);
  };
  int num = 0, size = s.size();
  for (int i = 0; i < size; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      num = num * 10 + (s[i] - '0');
      if (i >= size - 1 || s[i + 1] < '0' || s[i + 1] > '9')
        stk_num.push(num), num = 0;
    } else if (s[i] == '(') {
      stk_sym.push('(');
    } else if (s[i] == ')') {
      while (stk_sym.top() != '(')
        calc();
      stk_sym.pop();
    } else {
      while (!stk_sym.empty() && mp[s[i]] <= mp[stk_sym.top()])
        calc();
      stk_sym.push(s[i]);
    }
  }
  while (!stk_sym.empty())
    calc();
  cout << stk_num.top() << '\n';

  return 0;
}
