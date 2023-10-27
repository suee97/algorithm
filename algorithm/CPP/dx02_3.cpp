#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    
    int** board = new int*[n+1];
    for (int i = 0; i < n+1; i++) {
        board[i] = new int[m+1];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 처음 안전한 셀의 개수 구하기
    int** safe = new int*[n];
    for (int i = 0; i < n; i++) {
        safe[i] = new int[m];
    }

    int ans = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int tmp = -1;
        int mIndex;
        for (int j = 0; j < m; j++) {
            if (tmp < board[i][j]) {
                tmp = board[i][j];
                mIndex = j;
            }
        }
        board[i][m] = mIndex;
    }

    for (int i = 0; i < m; i++) {
        int tmp = -1;
        int mIndex;
        for (int j = 0; j < n; j++) {
            if (tmp < board[j][i]) {
                tmp = board[j][i];
                mIndex = j;
            }
        }
        board[n][i] = mIndex;
    }

    cout << "\nboard\n";
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < m+1; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            safe[i][j] = 0;
            if (board[i][j] >= board[i][board[i][m]] && board[i][j] >= board[board[n][j]][j]) {
                safe[i][j] = 1;
                ans++;
            }
        }
    }

    cout << "\nsafe" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << safe[i][j] << ' ';
        }
        cout << '\n';
    }

    while (q--) {
        int r, c, x;
        cin >> r >> c >> x;
        
        if (safe[r-1][c-1] == 1) {
            board[r-1][c-1] = x;
            sum += ans;
            continue;
        }

        int rr=0, cc=0;
        if (x > board[r-1][board[r-1][m]]) {
            if (safe[r-1][board[r-1][m]]) {
                ans--;
                safe[r-1][board[r-1][m]] = 0;
            }
            board[r-1][m] = c-1;
            rr=1;
        }

        if (x > board[board[n][c-1]][c-1]) {
            if (safe[board[n][c-1]][c-1]) {
                ans--;
                safe[board[n][c-1]][c-1] = 0;
            }
            board[n][c-1] = r-1;
            cc=1;
        }

        if (rr && cc) {
            safe[r-1][c-1] = 1;
            ans++;
        }

        board[r-1][c-1] = x;
        
        sum += ans;
    }

    cout << "sum : " << sum;
}