#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[11][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long sum = 0;

    for (int i = 1; i < 10; i++) dp[i][1] = 1;
    for (int i = 2; i < 9; i++) dp[i][2] = 2;
    dp[0][2] = 1; dp[1][2] = 1; dp[9][2] = 1;    

    for (int i = 3; i <= n; i++) {
        dp[0][i] = dp[1][i-1];
        for (int j = 1; j <= 8; j++) {
            dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1]) % 1000000000;
        }
        dp[9][i] = dp[8][i-1];
    }

    for (int i = 0; i <= 9; i++) {
        sum += (dp[i][n] % 1000000000);
    }

    cout << sum % 1000000000;
}