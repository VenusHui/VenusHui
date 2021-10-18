#include <iostream>

using namespace std;

int main()
{
    int fromDate, totalDays, distance = 0;
    cin >> fromDate >> totalDays;
    while (totalDays > 0)
    {
        if (fromDate <= 5)
        {
            distance += 250;
            fromDate++;
            totalDays--;
        }
        else if (fromDate == 6)
        {
            fromDate = 1;
            totalDays -= 2;
        }
        else
        {
            fromDate = 1;
            totalDays--;
        }
    }
    cout << distance << endl;

    return 0;
}