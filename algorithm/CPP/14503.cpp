#include <bits/stdc++.h>
using namespace std;
int board[52][52];
int cleanBoard[52][52];
int n, m, curX, curY, curDir;
int cleanCount = 0;
int isStop = 0;

void cleanAndMove() {

    // 현재위치 청소
    if (cleanBoard[curX][curY] == 0) {
        cleanBoard[curX][curY] = 1;
        cleanCount++;
    }
    
    // 이동
    if (curDir == 0) {
        if (curY-1 >= 0 && cleanBoard[curX][curY-1] == 0 && board[curX][curY-1] == 0) {
            curY -= 1; curDir = 3;
            return;
        }
        if (curX+1 < n && cleanBoard[curX+1][curY] == 0 && board[curX+1][curY] == 0) {
            curX += 1; curDir = 2;
            return;
        }
        if (curY+1 < m && cleanBoard[curX][curY+1] == 0 && board[curX][curY+1] == 0) {
            curY += 1; curDir = 1;
            return;
        }
        if (curX-1 >= 0 && cleanBoard[curX-1][curY] == 0 && board[curX-1][curY] == 0) {
            curX -= 1; curDir = 0;
            return;
        }
        if (curX+1 < n && board[curX+1][curY] == 0) {
            curX += 1;
            return;
        }
        if (curX+1 >= n || board[curX+1][curY] == 1) {
            isStop = 1;
            return;
        }
    } else if (curDir == 1) {
        if (curX-1 >= 0 && cleanBoard[curX-1][curY] == 0 && board[curX-1][curY] == 0) {
            curX -= 1; curDir = 0;
            return;
        }
        if (curY-1 >= 0 && cleanBoard[curX][curY-1] == 0 && board[curX][curY-1] == 0) {
            curY -= 1; curDir = 3;
            return;
        }
        if (curX+1 < n && cleanBoard[curX+1][curY] == 0 && board[curX+1][curY] == 0) {
            curX += 1; curDir = 2;
            return;
        }
        if (curY+1 < m && cleanBoard[curX][curY+1] == 0 && board[curX][curY+1] == 0) {
            curY += 1; curDir = 1;
            return;
        }
        if (curY-1 >= 0 && board[curX][curY-1] == 0) {
            curY -= 1;
            return;
        }
        if (curY-1 < 0 || board[curX][curY-1] == 1) {
            isStop = 1;
            return;
        }
    } else if (curDir == 2) {
        if (curY+1 < m && cleanBoard[curX][curY+1] == 0 && board[curX][curY+1] == 0) {
            curY += 1; curDir = 1;
            return;
        }
        if (curX-1 >= 0 && cleanBoard[curX-1][curY] == 0 && board[curX-1][curY] == 0) {
            curX -= 1; curDir = 0;
            return;
        }
        if (curY-1 >= 0 && cleanBoard[curX][curY-1] == 0 && board[curX][curY-1] == 0) {
            curY -= 1; curDir = 3;
            return;
        }
        if (curX+1 < n && cleanBoard[curX+1][curY] == 0 && board[curX+1][curY] == 0) {
            curX += 1; curDir = 2;
            return;
        }
        if (curX-1 >= 0 && board[curX-1][curY] == 0) {
            curX -= 1;
            return;
        }
        if (curX-1 < 0 || board[curX-1][curY] == 1) {
            isStop = 1;
            return;
        }
    } else { // cirDir == 3
        if (curX+1 < n && cleanBoard[curX+1][curY] == 0 && board[curX+1][curY] == 0) {
            curX += 1; curDir = 2;
            return;
        }
        if (curY+1 < m && cleanBoard[curX][curY+1] == 0 && board[curX][curY+1] == 0) {
            curY += 1; curDir = 1;
            return;
        }
        if (curX-1 >= 0 && cleanBoard[curX-1][curY] == 0 && board[curX-1][curY] == 0) {
            curX -= 1; curDir = 0;
            return;
        }
        if (curY-1 >= 0 && cleanBoard[curX][curY-1] == 0 && board[curX][curY-1] == 0) {
            curY -= 1; curDir = 3;
            return;
        }
        if (curY+1 < m && board[curX][curY+1] == 0) {
            curY += 1;
            return;
        }
        if (curY+1 >= m || board[curX][curY+1] == 1) {
            isStop = 1;
            return;
        }
    }
}

int main() {
    cin >> n >> m >> curX >> curY >> curDir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    while (!isStop) {
        cleanAndMove();
    }
    cout << cleanCount;
}