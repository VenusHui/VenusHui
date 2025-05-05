#include <iostream>
#include <string>
using namespace std;

int main() {
  string ibsnCode;
  cin >> ibsnCode;
  int trueIdentifier = 0;
  int loop = 1, i = 0;
  while (loop <= 9) {
    if (ibsnCode.at(i) == '-') {
      i++;
      continue;
    } else {
      trueIdentifier += (ibsnCode.at(i) - '0') * loop;
      i++;
      loop++;
    }
  }
  trueIdentifier = trueIdentifier % 11;

  if (trueIdentifier == ibsnCode.at(ibsnCode.size() - 1) - '0' ||
      (trueIdentifier == 10 && ibsnCode.at(ibsnCode.size() - 1) == 'X')) {
    cout << "Right" << endl;
  } else {
    for (int i = 0; i <= 11; i++) {
      cout << ibsnCode.at(i);
    }

    if (trueIdentifier == 10) {
      cout << "X" << endl;
    } else {
      cout << trueIdentifier << endl;
    }
  }

  return 0;
}