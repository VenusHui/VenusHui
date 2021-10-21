#include <iostream>
#include <cstdio>
#include <fstream>
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
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    vector<bool> prime(b + 1, true);
    vector<int> ans;
    prime[0] = prime[1] = false;
    for (int i = 2; pow(i, 2) < b; i++)
    {
        if (prime[i])
        {
            for (int j = pow(i, 2); j <= b; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (unsigned int i = 0; i < prime.size(); i++)
    {
        if (prime[i])
        {
            ans.push_back(i);
        }
    }
    for (unsigned int i = 0; i < ans.size(); i++)
    {
        if (ans.at(i) >= a)
        {
            for (unsigned int j = i; j < ans.size(); j++)
            {
                function<int()> getBit = [&]()
                {
                    int bit = 0, temp = ans.at(j);
                    while (temp)
                    {
                        temp /= 10;
                        bit++;
                    }
                    return bit;
                };
                int right = 1, left = pow(10, getBit() - 1);
                function<bool()> isLoop = [&]()
                {
                    if (left <= right)
                    {
                        return true;
                    }
                    if (ans.at(j) / right % 10 == ans.at(j) / left % 10)
                    {
                        right *= 10;
                        left /= 10;
                        return isLoop();
                    }
                    return false;
                };
                if (isLoop())
                {
                    cout << ans.at(j) << endl;
                }
            }
            break;
        }
    }

    return 0;
}


// Upadate1: function isLoop()
bool isLoop(int x)
{
    int y = x, num = 0;
    while (y != 0)
    {
        num = num * 10 + y % 10;
        y /= 10;
    }
    if (num == x)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    vector<bool> prime(b + 1, true);
    vector<int> ans;
    prime[0] = prime[1] = false;
    for (int i = 2; pow(i, 2) < b; i++)
    {
        if (prime[i])
        {
            for (int j = pow(i, 2); j <= b; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (unsigned int i = 0; i < prime.size(); i++)
    {
        if (prime[i])
        {
            ans.push_back(i);
        }
    }
    for (unsigned int i = 0; i < ans.size(); i++)
    {
        if (ans.at(i) >= a)
        {
            for (unsigned int j = i; j < ans.size(); j++)
            {
                if (isLoop(ans.at(j)))
                {
                    cout << ans.at(j) << endl;
                }
            }
            break;
        }
    }

    return 0;
}