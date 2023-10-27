#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int board[n][3];
    int select[n][3];
    int dp[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
            select[i][j] = 0;
        }
    }

    dp[0] = INT_MAX;
    int minIndex;
    for (int i = 0; i < 3; i++) {
        if (board[0][i] < dp[0]) {
            dp[0] = board[0][i];
            minIndex = i;
        }
    }
    select[0][minIndex] = 1;

    dp[1] = INT_MAX;
    minIndex = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if (dp[1] > board[0][i] + board[1][j]) {
                dp[1] = board[0][i] + board[1][j];
                minIndex = j;
            }
        }
    }
    select[1][minIndex] = 1;

    
}