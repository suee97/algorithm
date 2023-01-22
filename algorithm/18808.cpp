#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[50][50];
int s_n, s_m;
int curSticker[20][20];


void initSticker() {
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            curSticker[i][j] = 0;
}

bool putSticker() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + s_n > n || j + s_m > m) continue;
            bool isPossible = true;
            for (int s_i = 0; s_i < s_n; s_i++) {
                for (int s_j = 0; s_j < s_m; s_j++) {
                    if (curSticker[s_i][s_j] == 1 && board[i+s_i][j+s_j] != 0) {
                        isPossible = false;
                    }
                }
            }
            if (isPossible) {
                for (int s_i = 0; s_i < s_n; s_i++) {
                    for (int s_j = 0; s_j < s_m; s_j++) {
                        if (curSticker[s_i][s_j] == 1) {
                            board[i+s_i][j+s_j] = 1;
                        }                        
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void rotateSticker() {
    int tmp_curSticker[20][20];
    int tmp_n, tmp_m;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            tmp_curSticker[i][j] = 0;
        }
    }
    for (int i = 0; i < s_n; i++) {
        for (int j = 0; j < s_m; j++) {
            if (curSticker[i][j] == 1) {
                tmp_curSticker[j][s_n - i - 1] = 1;
            } else {
                tmp_curSticker[j][s_n - i - 1] = 0;
            }
        }
    }
    initSticker();
    tmp_n = s_m;
    tmp_m = s_n;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            curSticker[i][j] = tmp_curSticker[i][j];
        }
    }

    s_n = s_m;
    s_m = tmp_m;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        initSticker();
        cin >> s_n >> s_m;
        for (int j = 0; j < s_n; j++) 
            for (int l = 0; l < s_m; l++) 
                cin >> curSticker[j][l];
        if (putSticker()) {
            continue;
        }
        rotateSticker();
        if (putSticker()) {
            continue;
        }
        rotateSticker();
        if (putSticker()) {
            continue;
        }
        rotateSticker();
        if (putSticker()) {
            continue;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) count++;
        }
    }
    cout << count << endl;
}