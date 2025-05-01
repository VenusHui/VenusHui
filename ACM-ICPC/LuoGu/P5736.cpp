#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
  if (num == 2) {
    return true;
  }
  if (num % 2 == 0 || num < 2) {
    return false;
  }
  for (int i = 3; i < num; i += 2) {
    if (num % i == 0 && num != i) {
      return false;
    }
  }

  return true;
}

int main() {
  int num;
  cin >> num;
  vector<int> numVec;
  int temp;
  for (int i = 0; i < num; i++) {
    cin >> temp;
    numVec.push_back(temp);
  }

  for (int i = 0; i < num; i++) {
    if (isPrime(numVec.at(i))) {
      cout << numVec.at(i) << " ";
    }
  }

  return 0;
}