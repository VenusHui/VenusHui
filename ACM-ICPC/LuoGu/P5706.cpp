#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  const int cupNum = 2;
  double totalDrink;
  int sdtNum;
  cin >> totalDrink >> sdtNum;
  cout << fixed << setprecision(3) << totalDrink / sdtNum << endl
       << sdtNum * cupNum << endl;

  return 0;
}