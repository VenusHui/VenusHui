#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int h, m;
    h = c - a;
    m = d - b;
    if (m < 0)
    {
        h--;
        m += 60;
    }
    cout << h << " " << m;
    return 0;
}