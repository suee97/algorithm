#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        int t, p; cin >> t >> p;
        cout << (t > 1 ? 0 : p);
        return 0;
    }

    vector<int> T(n), P(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i] >> P[i];
    }

    vector<int> dp(n+1);
    dp[n] = 0;
    dp[n-1] = T[n-1] > 1 ? 0 : P[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (i+T[i]-1 > n-1) {
            dp[i] = dp[i+1];
        } else {
            dp[i] = max(dp[i+T[i]]+P[i], dp[i+1]);
        }
    }

    // find max
    int ans = 0;
    for (auto e: dp) {
        ans = max(ans, e);
    }

    cout << ans;
    
}