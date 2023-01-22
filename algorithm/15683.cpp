// fail
#include <bits/stdc++.h>
using namespace std;

char board[8][8];
int n, m;
void printBoard();
int getRightLineZero(int x, int y, bool isColor);
int getLeftLineZero(int x, int y, bool isColor);
int getTopLineZero(int x, int y, bool isColor);
int getBottomLineZero(int x, int y, bool isColor);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int cctvNum = 5; cctvNum > 0; cctvNum--) {
        // i : 5 4 3 2 1
        if (cctvNum == 5) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == '5') {
                        getRightLineZero(i, j, true);
                        getLeftLineZero(i, j, true);
                        getTopLineZero(i, j, true);
                        getBottomLineZero(i, j, true);
                    }
                }
            }
        }
        if (cctvNum == 4) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == '4') {
                        int R = getRightLineZero(i, j, false);
                        int L = getLeftLineZero(i, j, false);
                        int T = getTopLineZero(i, j, false);
                        int B = getBottomLineZero(i, j, false);
                        int max = 0;
                        char arr[3];
                        if (R + L + T > max) {
                            max = R + L + T;
                            arr[0] = 'R'; arr[1] = 'L'; arr[2] = 'T';
                        }
                        if (R + B + T > max) {
                            max = R + B + T;
                            arr[0] = 'R'; arr[1] = 'B'; arr[2] = 'T';
                        }
                        if (R + L + B > max) {
                            max = R + L + B;
                            arr[0] = 'R'; arr[1] = 'L'; arr[2] = 'B';
                        }
                        if (B + L + T > max) {
                            max = B + L + T;
                            arr[0] = 'B'; arr[1] = 'L'; arr[2] = 'T';
                        }
                        for (int ttt = 0; ttt < 3; ttt++) {
                            switch (arr[ttt]) {
                                case 'R':
                                    getRightLineZero(i, j, true);
                                    break;
                                case 'L':
                                    getLeftLineZero(i, j, true);
                                    break;
                                case 'T':
                                    getTopLineZero(i, j, true);
                                    break;
                                default:
                                    getBottomLineZero(i, j, true);
                                    break;
                            }
                        }
                    }
                }
            }
        }
        if (cctvNum == 3) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == '3') {
                        int R = getRightLineZero(i, j, false);
                        int L = getLeftLineZero(i, j, false);
                        int T = getTopLineZero(i, j, false);
                        int B = getBottomLineZero(i, j, false);
                        int max = 0;
                        char arr[2];
                        if (T + R > max) {
                            max = T + R;
                            arr[0] = 'T'; arr[1] = 'R';
                        }
                        if (B + R > max) {
                            max = R + B;
                            arr[0] = 'B'; arr[1] = 'R';
                        }
                        if (L + B > max) {
                            max = L + B;
                            arr[0] = 'L'; arr[1] = 'B';
                        }
                        if (T + L > max) {
                            max = T + L;
                            arr[0] = 'T'; arr[1] = 'L';
                        }
                        for (int ttt = 0; ttt < 2; ttt++) {
                            switch (arr[ttt]) {
                                case 'R':
                                    getRightLineZero(i, j, true);
                                    break;
                                case 'L':
                                    getLeftLineZero(i, j, true);
                                    break;
                                case 'T':
                                    getTopLineZero(i, j, true);
                                    break;
                                default:
                                    getBottomLineZero(i, j, true);
                                    break;
                            }
                        }
                    }
                }
            }
        }
        if (cctvNum == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == '2') {
                        int R = getRightLineZero(i, j, false);
                        int L = getLeftLineZero(i, j, false);
                        int T = getTopLineZero(i, j, false);
                        int B = getBottomLineZero(i, j, false);
                        int max = 0;
                        char arr[2];
                        if (L + R > max) {
                            max = L + R;
                            arr[0] = 'L'; arr[1] = 'R';
                        }
                        if (T + B > max) {
                            max = T + B;
                            arr[0] = 'T'; arr[1] = 'B';
                        }
                        for (int ttt = 0; ttt < 2; ttt++) {
                            switch (arr[ttt]) {
                                case 'R':
                                    getRightLineZero(i, j, true);
                                    break;
                                case 'L':
                                    getLeftLineZero(i, j, true);
                                    break;
                                case 'T':
                                    getTopLineZero(i, j, true);
                                    break;
                                default:
                                    getBottomLineZero(i, j, true);
                                    break;
                            }
                        }
                    }
                }
            }
        }
        if (cctvNum == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == '1') {
                        int R = getRightLineZero(i, j, false);
                        int L = getLeftLineZero(i, j, false);
                        int T = getTopLineZero(i, j, false);
                        int B = getBottomLineZero(i, j, false);
                        int max = 0;
                        char arr[1];
                        if (T > max) {
                            max = T;
                            arr[0] = 'T';
                        }
                        if (R > max) {
                            max = R;
                            arr[0] = 'R';
                        }
                        if (B > max) {
                            max = B;
                            arr[0] = 'B';
                        }
                        if (L > max) {
                            max = L;
                            arr[0] = 'L';
                        }
                        for (int ttt = 0; ttt < 1; ttt++) {
                            switch (arr[ttt]) {
                                case 'R':
                                    getRightLineZero(i, j, true);
                                    break;
                                case 'L':
                                    getLeftLineZero(i, j, true);
                                    break;
                                case 'T':
                                    getTopLineZero(i, j, true);
                                    break;
                                default:
                                    getBottomLineZero(i, j, true);
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }

    printBoard();
    
}

void printBoard() {
    int zeroCount = 0;
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '0') {
                zeroCount++;
            }
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << zeroCount;
}

int getRightLineZero(int x, int y, bool isColor) {
    int count = 0;
    for (int i = y; i < m; i++) {
        if (board[x][i] == '6') break;
        if (board[x][i] == '0') {
            count++;
            if (isColor) {
                board[x][i] = '#';
            }
        }
    }
    return count;
}

int getLeftLineZero(int x, int y, bool isColor) {
    int count = 0;
    for (int i = y; i >= 0; i--) {
        if (board[x][i] == '6') break;
        if (board[x][i] == '0') {
            count++;
            if (isColor) {
                board[x][i] = '#';
            }
        }
    }
    return count;
}

int getTopLineZero(int x, int y, bool isColor) {
    int count = 0;
    for (int ii = x; ii >= 0; ii--) {
        if (board[ii][y] == '6') break;
        if (board[ii][y] == '0') {
            count++;
            if (isColor) {
                board[ii][y] = '#';
            }
        }
    }
    return count;
}

int getBottomLineZero(int x, int y, bool isColor) {
    int count = 0;
    for (int ii = x; ii < n; ii++) {
        if (board[ii][y] == '6') break;
        if (board[ii][y] == '0') {
            count++;
            if (isColor) {
                board[ii][y] = '#';
            }
        }
    }
    return count;
}