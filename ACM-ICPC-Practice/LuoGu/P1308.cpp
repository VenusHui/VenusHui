#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    string b;
    getline(cin, a); // within the space
    getline(cin, b);
    for (int i = 0; i < a.length(); ++i)
    {
        a[i] = tolower(a[i]);
    }
    for (int i = 0; i < b.length(); ++i)
    {
        b[i] = tolower(b[i]);
    }

    a = ' ' + a + ' ';
    b = ' ' + b + ' ';

    if (b.find(a) == -1) // Not found
    {
        cout << -1 << endl;
    }
    else
    {
        int pos1 = b.find(a);
        int pos2 = b.find(a), s = 0;
        while (pos2 != -1)
        {
            s++;
            pos2 = b.find(a, pos2 + 1);
        }
        cout << s << " " << pos1 << endl;
    }

    return 0;
}