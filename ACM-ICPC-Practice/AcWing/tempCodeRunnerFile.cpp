vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + pre[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';