#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];
int newBoard[20][20];
int maxBlock = 0;

void moveNewBoard(int dir) {
    
    // 위로
    if (dir == 0) {

        // 1. 이동
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = 0; j < n; j++) {
                if (newBoard[j][i] != 0) q.push(newBoard[j][i]);
                newBoard[j][i] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (q.empty()) continue;
                newBoard[j][i] = q.front();
                q.pop();
            }
        }

        // 2. 같은게 붙어있으면 더하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                if (newBoard[j][i] == 0) continue;
                if (newBoard[j][i] == newBoard[j+1][i]) {
                    newBoard[j][i] *= 2;
                    newBoard[j+1][i] = 0;
                }
            }
        }

        // 3. 이동
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = 0; j < n; j++) {
                if (newBoard[j][i] != 0) q.push(newBoard[j][i]);
                newBoard[j][i] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (q.empty()) continue;
                newBoard[j][i] = q.front();
                q.pop();
            }
        }
    }

    // 오른쪽으로
    if (dir == 1) {

        // 1. 이동
        for (int i = 0; i < n; i++) {
            stack<int> s;
            for (int j = 0; j < n; j++) {
                if (newBoard[i][j] != 0) s.push(newBoard[i][j]);
                newBoard[i][j] = 0;
            }
            for (int j = n-1; j >= 0; j--) {
                if (s.empty()) continue;
                newBoard[i][j] = s.top();
                s.pop();
            }
        }

        // 2. 같은게 붙어있으면 더하기
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j > 0; j--) {
                if (newBoard[i][j] == 0) continue;
                if (newBoard[i][j] == newBoard[i][j-1]) {
                    newBoard[i][j] *= 2;
                    newBoard[i][j-1] = 0;
                }
            }
        }

        // 3. 이동
        for (int i = 0; i < n; i++) {
            stack<int> s;
            for (int j = 0; j < n; j++) {
                if (newBoard[i][j] != 0) s.push(newBoard[i][j]);
                newBoard[i][j] = 0;
            }
            for (int j = n-1; j >= 0; j--) {
                if (s.empty()) continue;
                newBoard[i][j] = s.top();
                s.pop();
            }
        }
    }

    // 아래로
    if (dir == 2) {

        // 1. 이동
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = n-1; j >= 0; j--) {
                if (newBoard[j][i] != 0) q.push(newBoard[j][i]);
                newBoard[j][i] = 0;
            }
            for (int j = n-1; j >= 0; j--) {
                if (q.empty()) continue;
                newBoard[j][i] = q.front();
                q.pop();
            }
        }

        // 2. 같은게 붙어있으면 더하기
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j > 0; j--) {
                if (newBoard[j][i] == 0) continue;
                if (newBoard[j][i] == newBoard[j-1][i]) {
                    newBoard[j][i] *= 2;
                    newBoard[j-1][i] = 0;
                }
            }
        }

        // 3. 이동
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = n-1; j >= 0; j--) {
                if (newBoard[j][i] != 0) q.push(newBoard[j][i]);
                newBoard[j][i] = 0;
            }
            for (int j = n-1; j >= 0; j--) {
                if (q.empty()) continue;
                newBoard[j][i] = q.front();
                q.pop();
            }
        }
    }

    // 왼쪽으로
    if (dir == 3) {

        // 1. 이동
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = 0; j < n; j++) {
                if (newBoard[i][j] != 0) q.push(newBoard[i][j]);
                newBoard[i][j] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (q.empty()) continue;
                newBoard[i][j] = q.front();
                q.pop();
            }
        }

        // 2. 같은게 붙어있으면 더하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                if (newBoard[i][j] == 0) continue;
                if (newBoard[i][j] == newBoard[i][j+1]) {
                    newBoard[i][j] *= 2;
                    newBoard[i][j+1] = 0;
                }
            }
        }

        // 3. 이동
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = 0; j < n; j++) {
                if (newBoard[i][j] != 0) q.push(newBoard[i][j]);
                newBoard[i][j] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (q.empty()) continue;
                newBoard[i][j] = q.front();
                q.pop();
            }
        }
    }
}

void printNewBoard() {
    cout << endl << ">> newBoard" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << newBoard[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int tmp = 0; tmp < 4*4*4*4*4; tmp++) {
        int a = tmp / (4*4*4*4);
        int b = (tmp % (4*4*4*4)) / (4*4*4);
        int c = (tmp % (4*4*4)) / (4*4);
        int d = (tmp % (4*4)) / (4);
        int e = (tmp % (4)) / 1;

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                newBoard[i][j] = board[i][j];
        
        moveNewBoard(a);
        moveNewBoard(b);
        moveNewBoard(c);
        moveNewBoard(d);
        moveNewBoard(e);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (newBoard[i][j] > maxBlock) {
                    maxBlock = newBoard[i][j];
                }
            }
        }
    }

    cout << maxBlock;
}