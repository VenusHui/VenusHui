// /**
//  * @platform: Nowcoder_PDD
//  * @problem: pdd_testD 
//  * @version: Contest Version
//  * @author: VenusHui
//  * @date: 2023-03-12
//  */
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int n;
//     cin >> n;
//     vector<int> a(n), pre(n + 1);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
//     for (int i = 1; i <= n; i++) {
//         cout << floor((1.0 * pre[i]) / i + 0.5) << " ";
//     }
//     cout << '\n';
//     priority_queue<int> maxq;
//     priority_queue<int, vector<int>, greater<int>> minq;
//     int mark = a[0];
//     cout << a[0] << " ";
//     function<int()> calc = [&] {
//         return static_cast<int>(floor((1.0 * maxq.top() + minq.top()) / 2 + 0.5));
//     };
//     for (int i = 1; i < n; i++) {
//         if (i % 2) {
//             maxq.push(min(mark, a[i]));
//             minq.push(max(mark, a[i]));
//             cout << calc() << " ";
//         }
//         else {
//             if (a[i] <= calc()) {
//                 maxq.push(a[i]);
//                 mark = maxq.top();
//                 maxq.pop();
//             }
//             else {
//                 minq.push(a[i]);
//                 mark = minq.top();
//                 minq.pop();
//             }
//             cout << mark << " ";
//         }
//     }
//     cout << '\n';

//     return 0;
// }


/**
 * @platform: Nowcoder_PDD
 * @problem: pdd_testD 
 * @version: Contest Version
 * @author: VenusHui
 * @date: 2023-03-12
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
    vector<int> a(n), pre(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    for (int i = 1; i <= n; i++) {
        cout << floor((1.0 * pre[i]) / i + 0.5) << " ";
    }
    cout << '\n';
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        if (i == 0) arr.push_back(a[i]);
        else {
            int l = 0, r = arr.size() - 1;
            while (l < r) {
                int m = (l + r) >> 1;
                if (arr[m] < a[i]) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            if (a[i] <= arr[l]) arr.insert(arr.begin() + l, a[i]);
            else arr.insert(arr.begin() + l + 1, a[i]);
        }
        if (arr.size() % 2) {
            cout << arr[arr.size() / 2] << " ";
        }
        else {
            cout << floor((1.0 * arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2 + 0.5) << " ";
        }
    }
    cout << '\n';

    return 0;
}
