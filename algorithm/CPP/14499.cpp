#include <bits/stdc++.h>
using namespace std;

int curX, curY;
int n, m;
int board[20][20];
int dice[4][3];
int newDice[4][3];

void moveDice(int dir) {
    // 동
    if (dir == 1 && (curY + 1 < m)) {
        newDice[0][1] = dice[0][1];
        newDice[1][0] = dice[3][1];
        newDice[1][1] = dice[1][0];
        newDice[1][2] = dice[1][1];
        newDice[2][1] = dice[2][1];
        newDice[3][1] = dice[1][2];
        copy(&newDice[0][0], &newDice[0][0] + 12, &dice[0][0]);
        curY++;
        if (board[curX][curY] == 0) {
            board[curX][curY] = dice[3][1];
        } else {
            dice[3][1] = board[curX][curY];
            board[curX][curY] = 0;
        }
        cout << dice[1][1] << endl;
    }

    // 서
    if (dir == 2 && (curY - 1 >= 0)) {
        newDice[0][1] = dice[0][1];
        newDice[1][2] = dice[3][1];
        newDice[3][1] = dice[1][0];
        newDice[1][0] = dice[1][1];
        newDice[2][1] = dice[2][1];
        newDice[1][1] = dice[1][2];
        copy(&newDice[0][0], &newDice[0][0] + 12, &dice[0][0]);
        curY--;
        if (board[curX][curY] == 0) {
            board[curX][curY] = dice[3][1];
        } else {
            dice[3][1] = board[curX][curY];
            board[curX][curY] = 0;
        }
        cout << dice[1][1] << endl;
    }

    // 북
    if (dir == 3 && (curX - 1 >= 0)) {
        newDice[3][1] = dice[0][1];
        newDice[2][1] = dice[3][1];
        newDice[1][0] = dice[1][0];
        newDice[0][1] = dice[1][1];
        newDice[1][1] = dice[2][1];
        newDice[1][2] = dice[1][2];
        copy(&newDice[0][0], &newDice[0][0] + 12, &dice[0][0]);
        curX--;
        if (board[curX][curY] == 0) {
            board[curX][curY] = dice[3][1];
        } else {
            dice[3][1] = board[curX][curY];
            board[curX][curY] = 0;
        }
        cout << dice[1][1] << endl;
    }

    // 남
    if (dir == 4 && (curX + 1 < n)) {
        newDice[1][1] = dice[0][1];
        newDice[0][1] = dice[3][1];
        newDice[1][0] = dice[1][0];
        newDice[2][1] = dice[1][1];
        newDice[3][1] = dice[2][1];
        newDice[1][2] = dice[1][2];
        copy(&newDice[0][0], &newDice[0][0] + 12, &dice[0][0]);
        curX++;
        if (board[curX][curY] == 0) {
            board[curX][curY] = dice[3][1];
        } else {
            dice[3][1] = board[curX][curY];
            board[curX][curY] = 0;
        }
        cout << dice[1][1] << endl;
    }
}

int main() {
    int moveCount;
    cin >> n >> m >> curX >> curY >> moveCount;

    // 지도 초기화
    for (int i = 0; i < 20; i++) 
        for (int j = 0; j < 20; j++)
            board[i][j] = -1;

    // 지도 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    // 이동 입력
    for (int i = 0; i < moveCount; i++) {
        int move;
        cin >> move;
        moveDice(move);
    }
}