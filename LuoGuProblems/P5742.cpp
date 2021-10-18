#include <iostream>
#include <cstring>
using namespace std;
struct student
{
    int id;             //学号
    double sc1, sc2;    //学业成绩和素质拓展成绩
    int score;          //学业成绩和素质拓展成绩的和
    double final_score; //综合分数
} a[1000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].id >> a[i].sc1 >> a[i].sc2;
        a[i].score = a[i].sc1 + a[i].sc2;
        a[i].final_score = a[i].sc1 * 0.7 + a[i].sc2 * 0.3;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i].score > 140 && a[i].final_score >= 80)
        {
            cout << "Excellent" << endl;
        }
        else
        {
            cout << "Not excellent" << endl;
        }
    }
    return 0;
}