#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    int n, m, h;
    cin >> m >> n >> h;
    int board[h][n][m];
    int vis[h][n][m];
    int dist[h][n][m];
    
    queue<tuple<int, int, int>> Q;

    // 초기화
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                dist[i][j][k] = -99; // 접근하지 못한 곳
                vis[i][j][k] = 0;
                if (board[i][j][k] == 1) {
                    Q.push({i, j, k});
                    dist[i][j][k] = 0;
                    vis[i][j][k] = 1;
                }
                if (board[i][j][k] == -1) {
                    dist[i][j][k] = -1; // 벽, 가지 못하는 곳
                }
            }
        }
    }
    
    // 로직
    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front(); // 높이, x, y
        Q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            
            if (nz < 0 || nx < 0 || ny < 0 || nz >= h || nx >= n || ny >= m) continue;
            if (vis[nz][nx][ny] == 1 || board[nz][nx][ny] != 0) continue;
            
            vis[nz][nx][ny] = 1;
            Q.push({nz, nx, ny});
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }

    int isFail = 0;
    int max = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[i][j][k] == -99) {
                    isFail = 1;
                }
                if (dist[i][j][k] > max) {
                    max = dist[i][j][k];
                }
            }
        }
    }    
    if (isFail) {
        cout << "-1";
    } else {
        cout << max;
    }
}