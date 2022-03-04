// 简单分数统计
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
    int n, m, k; // 朋友个数、题目个数、提交总次数
    cin >> n >> m >> k;
    vector<pair<string, int> > friends(n);  // 好朋友
    vector<pair<string, int> > problems(m); // 题目
    for (int i = 0; i < n; i++)
        cin >> friends[i].first;
    for (int i = 0; i < m; i++)
        cin >> problems[i].first >> problems[i].second;
    for (int i = 0; i < k; i++)
    {
        string submitName, problemName, result;
        cin >> submitName >> problemName >> result;
        if (result == "AC")
        {
            int prNum = 0, frNum = 0;
            bool prFlag = false, frFlag = false;
            for (int j = 0; j < m; j++)
            {
                if (problemName == problems[j].first)
                {
                    prNum = j;
                    prFlag = true;
                    break;
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (submitName == friends[j].first)
                {
                    frNum = j;
                    frFlag = true;
                    break;
                }
            }
            if (prFlag && frFlag)
                friends[frNum].second += problems[prNum].second;
        }
    }
    for (int i = 0; i < n; i++)
        cout << friends[i].first << " " << friends[i].second << endl;

    return 0;
}