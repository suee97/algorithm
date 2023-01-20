#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    int board[n][n];
    int maxHeight = 0;
    int maxAreaCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] > maxHeight) {
                maxHeight = board[i][j];
            }
        }
    }

    for (int rainHeight = 0; rainHeight <= maxHeight; rainHeight++) {

        queue<pair<int, int>> Q;
        int areaCount = 0;
        int vis[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = 0;
            }
        }

        // 탐색 시작
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > rainHeight && vis[i][j] == 0) {
                    areaCount++;
                    Q.push({i, j});
                    vis[i][j] = 1;
                    while (!Q.empty()) {
                        pair<int, int> cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if (board[nx][ny] <= rainHeight || vis[nx][ny] == 1) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        if (maxAreaCount < areaCount) {
            maxAreaCount = areaCount;
        }
    }
    cout << maxAreaCount;
}