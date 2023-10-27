#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002] = {};
int vis[1002][1002] = {};
int needDay[1002][1002] = {};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;
int maxDay = 0;
int isError = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            needDay[i][j] = -9;
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({i, j});
                vis[i][j] = 1;
                needDay[i][j] = 0;
            }
            if (board[i][j] == -1) {
                needDay[i][j] = -1;
            }
        }
    }
    
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == -1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            needDay[nx][ny] = needDay[cur.X][cur.Y] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (needDay[i][j] == -9) {
                isError = 1;
            }
            if (needDay[i][j] > maxDay) {
                maxDay = needDay[i][j];
            }
        }
    }
    if (isError == 1) {
        cout << "-1";
    } else {
        cout << maxDay;
    }
}