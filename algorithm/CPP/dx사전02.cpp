#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[m];
    }

    int* rowMax = new int[n]; // i번째 행에서 최대는 rowMax[i] (값 아님 인덱스)
    int* colMax = new int[m]; // i번째 열에서 최대는 colMax[i] (값 아님 인덱스)
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 처음 안전한 셀의 개수 구하기
    int safe[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            safe[i][j] = 0;
        }
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int maxIndex;
        int curMax = -1;
        for (int j = 0; j < m; j++) {
            if (board[i][j] > curMax) {
                maxIndex = j;
                curMax = board[i][j];
            }
        }
        int prev = curMax;
        for (int j = 0; j < n; j++) {
            curMax = max(curMax, board[j][maxIndex]);
        }
        if (prev == curMax) {
            ans++;
            safe[i][maxIndex] = 1;
        }
    }

    while (q--) {
        int r, c, x;
        cin >> r >> c >> x;
        
        board[r-1][c-1] = x;
        if (safe[r-1][c-1] == 1) {
            sum += ans;
            continue;
        }
        
        int isMax = 1;

        // 가로
        for (int i = 0; i < m; i++) {
            if (safe[r-1][i] == 1 && board[r-1][i] < x) {
                safe[r-1][i] = 0;
                ans--;
                break;
            }
            if (board[r-1][i] > x) {
                isMax = 0;
                break;
            }
        }

        if (isMax) {
            // 세로
            for (int i = 0; i < n; i++) {
                if (safe[i][c-1] == 1 && board[i][c-1] < x) {
                    safe[i][c-1] = 0;
                    ans--;
                    break;
                }
                if (board[i][c-1] > x) {
                    isMax = 0;
                    break;
                }
            }

            if (safe[r-1][c-1] != 1) {
                safe[r-1][c-1] = 1;
                ans++;
            }
        }
        sum += ans;
    }

    cout << sum;
}