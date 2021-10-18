#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    string name1, name2;
    int chinese1, math1, english1, chinese2, math2, english2;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> name1 >> chinese1 >> math1 >> english1;
        if (i == 0)
        {
            name2 = name1;
            chinese2 = chinese1;
            math2 = math1;
            english2 = english1;
        }

        if (chinese1 + math1 + english1 > chinese2 + math2 + english2)
        {
            name2 = name1;
            chinese2 = chinese1;
            math2 = math1;
            english2 = english1;
        }
    }
    cout << name2 << " " << chinese2 << " " << math2 << " " << english2 << endl;

    return 0;
}