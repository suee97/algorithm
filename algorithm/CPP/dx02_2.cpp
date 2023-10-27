#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    // int board[n][m];

    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int sum = 0;

    while (q--) {
        int ans = 0;

        int r, c, x;
        cin >> r >> c >> x;
        board[r - 1][c - 1] = x;

        for (int i = 0; i < n; i++) {
            int maxIndex;
            int curMax = -1;
            for (int j = 0; j < m; j++) {
                if (board[i][j] > curMax) {
                    maxIndex = j;
                    curMax = board[i][j];
                }
            }

            int tmp = -1;
            for (int j = 0; j < n; j++) {
                tmp = max(tmp, board[j][maxIndex]);
            }

            if (curMax == tmp) {
                ans++;
            }
        }
        sum += ans;
    }

    cout << sum;
}