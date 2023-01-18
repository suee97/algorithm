#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char color[3] = {'R', 'G', 'B'};
char board[102][102];

int main() {
    int count_1 = 0;
    int count_2 = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            board[i][j] = s[j];
        }
    }
    
    for (int colNum = 0; colNum < 3; colNum++) {
        int vis[102][102] = {0};
        queue<pair<int, int>> Q;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == color[colNum] && vis[i][j] != 1) {
                    Q.push({i, j});
                    vis[i][j] = 1;
                    while (!Q.empty()) {
                        pair<int, int> cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (vis[nx][ny] == 1 || board[nx][ny] != color[colNum]) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                    count_1++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'G') {
                board[i][j] = 'R';
            }
        }
    }
    
    for (int colNum = 0; colNum < 3; colNum++) {
        int vis[102][102] = {0};
        queue<pair<int, int>> Q;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == color[colNum] && vis[i][j] != 1) {
                    Q.push({i, j});
                    vis[i][j] = 1;
                    while (!Q.empty()) {
                        pair<int, int> cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (vis[nx][ny] == 1 || board[nx][ny] != color[colNum]) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                    count_2++;
                }
            }
        }
    }
    
    cout << count_1 << ' ' << count_2;
}