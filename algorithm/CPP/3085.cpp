#include <iostream>
using namespace std;

char board[51][51];
char newBoard[51][51];

int getMax(int n) {
    int maxCnt = 1;

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (newBoard[i][j] == newBoard[i][j-1]) {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            } else {
                cnt = 1;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (newBoard[i][j] == newBoard[i-1][j]) {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            } else {
                cnt = 1;
            }
        }
    }
    
    return maxCnt;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            newBoard[i][j] = board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 오른쪽
            if (j != n-1) {
                newBoard[i][j] = board[i][j+1];
                newBoard[i][j+1] = board[i][j];
                ans = max(ans, getMax(n));
                newBoard[i][j] = board[i][j];
                newBoard[i][j+1] = board[i][j+1];
            }

            // 아래
            if (i != n-1) {
                newBoard[i][j] = board[i+1][j];
                newBoard[i+1][j] = board[i][j];
                ans = max(ans, getMax(n));
                newBoard[i][j] = board[i][j];
                newBoard[i+1][j] = board[i+1][j];
            }

        }
    }

    cout << ans;
}