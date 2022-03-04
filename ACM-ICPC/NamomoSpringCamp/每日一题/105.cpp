// 德州扑克
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
typedef long long ll;
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    const int size = 5;
    vector<pair<int, int> > poke(size); // (点数，花色)
    for (int i = 0; i < size; i++)
        cin >> poke[i].first;
    for (int i = 0; i < size; i++)
        cin >> poke[i].second;
    // 最大点数
    bool maxFlag = false;
    sort(poke.begin(), poke.end());
    if (poke[size - 1].first == 14) // Ace
        maxFlag = true;

    // 相同点数
    vector<pair<int, int> > sameNum;
    sameNum.push_back(make_pair(poke[0].first, 1));
    for (int i = 1; i < size; i++)
    {
        if (poke[i].first == sameNum.back().first)
            sameNum.back().second++;
        else
            sameNum.push_back(make_pair(poke[i].first, 1));
    }

    // 是否为顺
    bool conFlag = true;
    int tmp = poke[0].first;
    for (int i = 0; i < size; i++, tmp++)
    {
        if (poke[i].first != tmp)
        {
            conFlag = false;
            break;
        }
    }

    // 是否同花
    bool floFlag = true;
    for (int i = 1; i < size; i++)
    {
        if (poke[i].second != poke[i - 1].second)
        {
            floFlag = false;
            break;
        }
    }

    if (conFlag) // 顺子
    {
        if (floFlag) // 同花
        {
            if (maxFlag) // Ace
            {
                cout << "ROYAL FLUSH" << endl;
                return 0;
            }
            cout << "STRAIGHT FLUSH" << endl;
            return 0;
        }
        cout << "STRAIGHT" << endl;
        return 0;
    }
    else
    {
        if (floFlag)
        {
            cout << "FLUSH" << endl;
            return 0;
        }
    }

    int num = sameNum.size();
    if (num == 1) // 四条
    {
        cout << "FOUR OF A KIND" << endl;
        return 0;
    }
    else if (num == 2)
    {
        if (sameNum[0].second == 4 || sameNum[1].second == 4)
        {
            cout << "FOUR OF A KIND" << endl;
            return 0;
        }
        else
        {
            cout << "FULL HOUSE" << endl;
            return 0;
        }
    }
    cout << "FOLD" << endl;

    return 0;
}