#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[502][502];
int maxSum = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 3 < m) {
                maxSum = max(maxSum, board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3]);
            }
            if (i + 3 < n) {
                maxSum = max(maxSum, board[i][j]+board[i+1][j]+board[i+2][j]+board[i+3][j]);
            }
            if (i + 1 < n && j + 1 < m) {
                maxSum = max(maxSum, board[i][j]+board[i+1][j]+board[i][j+1]+board[i+1][j+1]);
            }
            if (j + 1 < m && i + 2 < n) {
                maxSum = max(maxSum, board[i][j]+board[i+1][j]+board[i+2][j]+board[i+2][j+1]);
                maxSum = max(maxSum, board[i][j+1]+board[i+1][j+1]+board[i+2][j+1]+board[i+2][j]);
                maxSum = max(maxSum, board[i][j+1]+board[i][j]+board[i+1][j]+board[i+2][j]);
                maxSum = max(maxSum, board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i+2][j+1]);
            }
            if (j + 2 < m && i + 1 < n) {
                maxSum = max(maxSum, board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+1][j+2]);
                maxSum = max(maxSum, board[i+1][j]+board[i+1][j+1]+board[i+1][j+2]+board[i][j+2]);
                maxSum = max(maxSum, board[i+1][j]+board[i][j]+board[i][j+1]+board[i][j+2]);
                maxSum = max(maxSum, board[i][j]+board[i][j+1]+board[i][j+2]+board[i+1][j+2]);
            }
            if (j + 1 < m && i + 2 < n) {
                maxSum = max(maxSum, board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+2][j+1]);
                maxSum = max(maxSum, board[i][j+1]+board[i+1][j+1]+board[i+1][j]+board[i+2][j]);
            }
            if (j + 2 < m && i + 1 < n) {
                maxSum = max(maxSum, board[i][j+2]+board[i][j+1]+board[i+1][j+1]+board[i+1][j]);
                maxSum = max(maxSum, board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i+1][j+2]);
            }
            if (i + 1 < n && j + 2 < m) {
                maxSum = max(maxSum, board[i][j]+board[i][j+1]+board[i][j+2]+board[i+1][j+1]);
                maxSum = max(maxSum, board[i][j+1]+board[i+1][j+1]+board[i+1][j]+board[i+1][j+2]);
            }
            if (i + 2 < n && j + 1 < m) {
                maxSum = max(maxSum, board[i+1][j]+board[i+1][j+1]+board[i][j+1]+board[i+2][j+1]);
                maxSum = max(maxSum, board[i][j]+board[i+1][j]+board[i+2][j]+board[i+1][j+1]);
            }
        }
    }
    cout << maxSum;
}