// 포기

#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[12][12];
int minMoveCount = 0;
int moveCount = 0;
pair<char, int> goal = {'N', -1};
pair<int, int> R_pos;
pair<int, int> B_pos;

void initBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void move(int dir) {
    // 0: 왼쪽, 1: 오른쪽, 2: 위쪽, 3: 아래쪽
    pair<int, int> beforeR = R_pos;
    pair<int, int> beforeB = B_pos;
    if (dir == 0) {
        // R, B 같은 라인
        if (R_pos.first == B_pos.first) {
            // R이 왼쪽
            if (R_pos.second < B_pos.second) {
                while (board[R_pos.first][R_pos.second] != '#') {
                    R_pos.second--;
                    if (board[R_pos.first][R_pos.second] == '0') {
                        goal = {'R', moveCount+1};
                        return;
                    }
                }
                R_pos.second++;
                board[beforeR.first][beforeR.second] = '.';
                board[R_pos.first][R_pos.second] = 'R';
                while (board[B_pos.first][B_pos.second] != '#') {
                    B_pos.second--;
                    if (board[B_pos.first][B_pos.second] == 'R') break;
                    if (board[B_pos.first][B_pos.second] == '0') {
                        goal = {'B', moveCount+1};
                        return;
                    }
                }
                B_pos.second++;
                board[beforeB.first][beforeB.second] = '.';
                board[B_pos.first][B_pos.second] = 'B';
            } else { // B가 왼쪽
                while (board[B_pos.first][B_pos.second] != '#') {
                    B_pos.second--;
                    if (board[B_pos.first][B_pos.second] == '0') {
                        goal = {'B', moveCount+1};
                        return;
                    }
                }
                B_pos.second++;
                board[beforeB.first][beforeB.second] = '.';
                board[B_pos.first][B_pos.second] = 'B';
                while (board[R_pos.first][R_pos.second] != '#') {
                    R_pos.second--;
                    if (board[R_pos.first][R_pos.second] == 'B') break;
                    if (board[R_pos.first][R_pos.second] == '0') {
                        goal = {'R', moveCount+1};
                        return;
                    }
                }
                R_pos.second++;
                board[beforeR.first][beforeR.second] = '.';
                board[R_pos.first][R_pos.second] = 'R';
            }

            moveCount++;
            return;
        }
        // R, B 다른 라인
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'R') {
                    while (board[R_pos.first][R_pos.second] != '#') {
                        R_pos.second--;
                    }
                    R_pos.second++;
                    board[beforeR.first][beforeR.second] = '.';
                    board[R_pos.first][R_pos.second] = 'R';
                }
                if (board[i][j] == 'B') {
                    while (board[B_pos.first][B_pos.second] != '#') {
                        B_pos.second--;
                    }
                    B_pos.second++;
                    board[beforeB.first][beforeB.second] = '.';
                    board[B_pos.first][B_pos.second] = 'B';
                }
            }
        }
        moveCount++;
        return;
    }
    if (dir == 1) {
        
        return;
    }
    if (dir == 2) {
        
        return;
    }
    if (dir == 3) {
        
        return;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'R') {
                R_pos = {i, j};
            }
            if (board[i][j] == 'B') {
                B_pos = {i, j};
            }
        }
    }
    move(0);
    printBoard();
    cout << moveCount;

    // for (int i = 0; i < 1048576; i++) {
    //     int tmp = i;
    //     initBoard();
    //     moveCount = 0;
    //     isSuccess = 0;
    //     for (int j = 0; j < 10; j++) {
    //         int val = tmp % 4;
    //         move(val);
    //         tmp /= 4;
    //     }
    //     if (!isSuccess) continue;
    //     minMoveCount = min(minMoveCount, moveCount);
    //     moveCount = 0;
    //     isSuccess = 0;
    // }
}