#include <iostream>
#include <string>

using namespace std;

char update(char ch, int pos);

int main() {
  int pos;
  string code;
  cin >> pos >> code;
  for (unsigned int i = 0; i < code.size(); i++) {
    cout << update(code.at(i), pos);
  }
  cout << endl;

  return 0;
}

char update(char ch, int pos) {
  ch -= 'a';
  ch += pos;
  if (ch >= 26) {
    ch -= 26;
  }
  ch += 'a';
  return ch;
}