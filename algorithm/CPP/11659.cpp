#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = v[0];
    for (int i = 2; i < n+1; i++) {
        dp[i] = dp[i-1] + v[i-1];
    }

    vector<int> ans;

    for (int i = 0; i < m; i++) {
        int st, end;
        cin >> st >> end;

        int res = dp[end] - dp[st-1];
        ans.push_back(res);
    }
    for (auto i: ans) {
        cout << i << '\n';
    }
}