#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[10][10];
char newBoard[10][10];
int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'X') {
                newBoard[i][j] = 'X';
            } else {
                newBoard[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'X') {
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx >= n || ny >= m || nx < 0 || ny < 0) {
                        cnt++;
                        continue;
                    }
                    if (board[nx][ny] == '.') {
                        cnt++;
                    }
                }
                if (cnt >= 3) {
                    newBoard[i][j] = '.';
                }
            } 
        }
    }

    vector<int> xs;
    vector<int> ys;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (newBoard[i][j] == 'X') {
                xs.push_back(i);
                ys.push_back(j);
            }
        }
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    for (int i = xs.front(); i <= xs.back(); i++) {
        for (int j = ys.front(); j <= ys.back(); j++) {
            cout << newBoard[i][j];
        }
        cout << '\n';
    }
}