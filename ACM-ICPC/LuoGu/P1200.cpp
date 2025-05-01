#include <iostream>
#include <string>

using namespace std;

int calc(string str) {
  int result = 1;
  for (unsigned int i = 0; i < str.size(); i++) {
    result *= (str.at(i) - 'A' + 1);
  }
  return result;
}

int main() {
  string starName, teamName;
  cin >> starName >> teamName;
  if (calc(starName) % 47 == calc(teamName) % 47) {
    cout << "GO" << endl;
  } else {
    cout << "STAY" << endl;
  }

  return 0;
}