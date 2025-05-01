#include <iostream>
using namespace std;
int main() {
  int sum;
  double money;
  cin >> sum;
  if (sum <= 150) {
    money = sum * 0.4463;
  } else if (sum >= 151 && sum <= 400) {
    money += 0.4463 * 150;
    money += 0.4663 * (sum - 150);
  } else {
    money += 0.4463 * 150;
    money += 0.4663 * 250;
    money += 0.5663 * (sum - 400);
  }
  money = int((money * 10) + 0.5) / 10.0;
  cout << money;
  return 0;
}