/**
 * @platform: Codeforces
 * @problem: EducationalCodeforcesRound137D 
 * @version: Contest Version (Unsolved)
 * @author: VenusHui
 * @date: 2022-10-25
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    function<int(string, char)> first_index_of = [&] (string str, char ch) {
        int size = str.size();
        for (int i = 0; i < size; i++) {
            if (str[i] == ch) {
                return i;
            }
        }
        return -1;
    };
    if (first_index_of(s, '1') == -1) {
        cout << "0" << '\n';
        return 0;
    }

    return 0;
}
