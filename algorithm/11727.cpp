#include <bits/stdc++.h>
using namespace std;

int n;
long long val;
long long dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = ((dp[i-1] * 2) + 1) % 10007;
        } else {
            dp[i] = ((dp[i-1] * 2) - 1) % 10007;
        }
    }
    cout << dp[n];
}   