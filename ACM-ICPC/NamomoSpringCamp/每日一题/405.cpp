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

// 

string convert(ll num, int s) {
    string ans;
    while (num)
    {
        int mod = num % s;
        if (mod >= 0 && mod <= 9) {
            ans.insert(ans.begin(), char('0' + mod));
        }
        else if (mod >= 10 && mod <= 35) {
            ans.insert(ans.begin(), char('A' + mod - 10));
        }
        else if (mod >= 36 && mod <= 61) {
            ans.insert(ans.begin(), char('a' + mod - 36));
        }
        num /= s;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> res(n);
    string ans;
    ll num = 0;
    for (int i = 0; i < n; i++) {
        cin >> res[i].first >> res[i].second;
        int size = res[i].second.size();
        for (int j = size - 1; j >= 0; j--) {
            if (res[i].second.at(j) >= '0' && res[i].second.at(j) <= '9') {
                ll pos = size - j - 1, tmp = res[i].second.at(j) - '0';
                num += pow(res[i].first, pos) * tmp;
            }
            if (res[i].second.at(j) >= 'A' && res[i].second.at(j) <= 'Z') {
                ll pos = size - j - 1, tmp = res[i].second.at(j) - 'A' + 10;
                num += pow(res[i].first, pos) * tmp;
            }
            if (res[i].second.at(j) >= 'a' && res[i].second.at(j) <= 'z') {
                ll pos = size - j - 1, tmp = res[i].second.at(j) - 'a' + 36;
                num += pow(res[i].first, pos) * tmp;
            }
        }
    }
    ans = convert(num, m);
    cout << ans << '\n';

    return 0;
}
