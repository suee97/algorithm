#include<bits/stdc++.h>
using namespace std;

int n, appleCount, dirCount;
int board[102][102];
int snake[102][102];
int snakeHeadX, snakeHeadY;
int tailX, tailY;
queue<pair<int, int>> tailQ;
int interval = 0;
int isStop = 0;
int curDir = 0;
queue<pair<int, char>> dirQ;

void move(int dir) {

    // 0: 동, 1: 남, 2: 서, 3: 북
    if (dir == 0) {
        // 갈 수 있는지 확인
        if (snakeHeadY + 1 >= n || snake[snakeHeadX][snakeHeadY+1] == 1) {
            isStop = 1;
            return;
        }
        // 헤드 이동
        snakeHeadY++;
        // 사과 있을 때
        if (board[snakeHeadX][snakeHeadY] == 1) {
            board[snakeHeadX][snakeHeadY] = 0;
            snake[snakeHeadX][snakeHeadY] = 1;
            tailQ.push({snakeHeadX, snakeHeadY});
        } else {
            // 사과 없을 때
            snake[snakeHeadX][snakeHeadY] = 1;
            pair<int, int> tailTmp = tailQ.front();
            snake[tailTmp.first][tailTmp.second] = 0;
            tailQ.pop();
            tailQ.push({snakeHeadX, snakeHeadY});
        }
        return;
    }
    if (dir == 1) {
        // 갈 수 있는지 확인
        if (snakeHeadX + 1 >= n || snake[snakeHeadX+1][snakeHeadY] == 1) {
            isStop = 1;
            return;
        }
        // 헤드 이동
        snakeHeadX++;
        // 사과 있을 때
        if (board[snakeHeadX][snakeHeadY] == 1) {
            board[snakeHeadX][snakeHeadY] = 0;
            snake[snakeHeadX][snakeHeadY] = 1;
            tailQ.push({snakeHeadX, snakeHeadY});
        } else {
            // 사과 없을 때
            snake[snakeHeadX][snakeHeadY] = 1;
            pair<int, int> tailTmp = tailQ.front();
            snake[tailTmp.first][tailTmp.second] = 0;
            tailQ.pop();
            tailQ.push({snakeHeadX, snakeHeadY});
        }
        return;
    }
    if (dir == 2) {
        // 갈 수 있는지 확인
        if (snakeHeadY - 1 < 0 || snake[snakeHeadX][snakeHeadY-1] == 1) {
            isStop = 1;
            return;
        }
        // 헤드 이동
        snakeHeadY--;
        // 사과 있을 때
        if (board[snakeHeadX][snakeHeadY] == 1) {
            board[snakeHeadX][snakeHeadY] = 0;
            snake[snakeHeadX][snakeHeadY] = 1;
            tailQ.push({snakeHeadX, snakeHeadY});
        } else {
            // 사과 없을 때
            snake[snakeHeadX][snakeHeadY] = 1;
            pair<int, int> tailTmp = tailQ.front();
            snake[tailTmp.first][tailTmp.second] = 0;
            tailQ.pop();
            tailQ.push({snakeHeadX, snakeHeadY});
        }
        return;
    }
    if (dir == 3) {
        // 갈 수 있는지 확인
        if (snakeHeadX - 1 < 0 || snake[snakeHeadX-1][snakeHeadY] == 1) {
            isStop = 1;
            return;
        }
        // 헤드 이동
        snakeHeadX--;
        // 사과 있을 때
        if (board[snakeHeadX][snakeHeadY] == 1) {
            board[snakeHeadX][snakeHeadY] = 0;
            snake[snakeHeadX][snakeHeadY] = 1;
            tailQ.push({snakeHeadX, snakeHeadY});
        } else {
            // 사과 없을 때
            snake[snakeHeadX][snakeHeadY] = 1;
            pair<int, int> tailTmp = tailQ.front();
            snake[tailTmp.first][tailTmp.second] = 0;
            tailQ.pop();
            tailQ.push({snakeHeadX, snakeHeadY});
        }
        return;
    }
}

void setDir(char c) {
    // 0: 동, 1: 남, 2: 서, 3: 북
    if (curDir == 0) {
        if (c == 'L') {
            curDir = 3;
        } else { // c == 'D'
            curDir = 1;
        }
        return;
    }
    if (curDir == 1) {
        if (c == 'L') {
            curDir = 0;
        } else { // c == 'D'
            curDir = 2;
        }
        return;
    }
    if (curDir == 2) {
        if (c == 'L') {
            curDir = 1;
        } else { // c == 'D'
            curDir = 3;
        }
        return;
    }
    if (curDir == 3) {
        if (c == 'L') {
            curDir = 2;
        } else { // c == 'D'
            curDir = 0;
        }
        return;
    }
}

int main() {
    cin >> n >> appleCount;
    for (int i = 0; i < appleCount; i++) {
        int tmpX, tmpY;
        cin >> tmpX >> tmpY;
        board[tmpX-1][tmpY-1] = 1;
    }
    cin >> dirCount;
    for (int i = 0; i < dirCount; i++) {
        int tmpTime; char direction;
        cin >> tmpTime >> direction;
        dirQ.push({tmpTime, direction});
    }

    snake[0][0] = 1;
    snakeHeadX = 0; snakeHeadY = 0;
    tailX = 0; tailY = 0;
    tailQ.push({tailX, tailY});

    while (!isStop) {
        move(curDir);
        interval++;
        if (!dirQ.empty() && dirQ.front().first == interval) {
            setDir(dirQ.front().second);
            dirQ.pop();
        }
    }
    cout << interval;
}