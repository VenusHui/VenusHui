/**
 * @platform: AcWing
 * @problem: P828-2 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-01-14
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int top = 0;
    vector<int> stk;
    function<void(int)> push = [&] (int x) {
        if (stk.size() <= top) stk.push_back(x), top++;
        else stk[top++] = x;
    };
    function<void()> pop = [&] () {
        top--;
    };
    function<bool()> empty = [&] () {
        return top <= 0;
    };
    function<int()> query = [&] () {
        return stk[top - 1];
    };
    int m;
    cin >> m;
    while (m--) {
        string oper;
        cin >> oper;
        if (oper == "push") {
            int x;
            cin >> x;
            push(x);
        }
        if (oper == "pop") {
            pop();
        }
        if (oper == "empty") {
            if (empty()) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        if (oper == "query") {
            cout << query() << '\n';
        }
    }

    return 0;
}
