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
#include <unordered_map>
#include <stack>
#include <set>
#include <numeric>
#include <iomanip>
typedef long long ll;
using namespace std;

// Good Permutations

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const ll mod = 1e9 + 7;
    const int size = 1e6 + 1;
    vector<ll> res(size, 1), pow(size, 1);
    for (int i = 1; i <= size; i++) {
        res[i] = res[i - 1] * i % mod;
        pow[i] = 2 * pow[i - 1] % mod;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (res[n] - pow[n - 1] + mod) % mod << '\n';
    }
    
    return 0;
}
