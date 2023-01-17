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
int n, ans = INT_MAX, ss = 1, kk = 0;
bool *visited;
vector<pair<int, int> > foods;

void DFS(int kind)
{
    if (kind > n)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            ss *= foods.at(i).first;
            kk += foods.at(i).second;
            ans = min(ans, abs(ss - kk));
            DFS(kind + 1);
            visited[i] = false;
            ss /= foods.at(i).first;
            kk -= foods.at(i).second;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int s, k;
    cin >> n;
    visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s >> k;
        foods.push_back(make_pair(s, k));
    }
    delete[] visited;
    DFS(1);
    cout << ans << endl;
    return 0;
}