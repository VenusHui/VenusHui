#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

// P1098 [NOIP2007 提高组] 字符串的展开

string s;
int p1, p2, p3;

int main() {
  cin >> p1 >> p2 >> p3;
  char ch;
  bool pro = p3 == 1 ? true : false;
  switch (p1) {
  case 1:
    ch = 0;
    break;
  case 2:
    ch = 'a' - 'A';
    break;
  case 3:
    ch = '*';
    break;
  }
  cin >> s;
  int size = s.size();
  for (int i = 0; i < size; i++) {
    string tmp;
    tmp.clear();
    bool flag = false;
    if (s[i] == '-' && i - 1 >= 0) {
      if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' &&
          s[i + 1] <= '9' && s[i - 1] < s[i + 1])
        flag = true;
      if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' &&
          s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
        flag = true;
      if (flag) // 要转换
      {
        if (s[i - 1] >= '0' && s[i - 1] <= '9') // 数字
        {
          for (int j = s[i - 1] + 1; j < s[i + 1]; j++) {
            for (int k = 0; k < p2; k++)
              tmp += (ch == '*' ? '*' : char(j));
          }
        }
        if (s[i - 1] >= 'a' && s[i - 1] <= 'z') // 字母
        {
          for (int j = s[i - 1] + 1; j < s[i + 1]; j++) {
            for (int k = 0; k < p2; k++)
              tmp += (ch == '*' ? '*' : char(j - ch));
          }
        }
        if (!pro)
          reverse(tmp.begin(), tmp.end());
        cout << tmp;
      } else
        cout << s[i];
    } else
      cout << s[i];
  }
  cout << '\n';

  return 0;
}