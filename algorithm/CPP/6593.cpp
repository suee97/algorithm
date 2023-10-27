#include <bits/stdc++.h>
using namespace std;

int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};

int main() {
    while (true) {
        int h, n, m;
        cin >> h >> n >> m;
        if (h == 0 && n == 0 && m == 0) break;
        
        int x = 0;

        // 초기화
        char board[h][n][m];
        int vis[h][n][m];
        int dist[h][n][m];
        tuple<int, int, int> endPoint;
        queue<tuple<int, int, int>> Q;
        
        // 입력받기
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < n; j++) {
                string s;
                cin >> s;
                for (int k = 0; k < m; k++) {
                    board[i][j][k] = s[k];
                    dist[i][j][k] = -99;
                    vis[i][j][k] = 0;
                    if (s[k] == 'S') {
                        Q.push({i, j, k}); // starting point
                        vis[i][j][k] = 1;
                        dist[i][j][k] = 0;
                    }
                    if (s[k] == 'E') {
                        endPoint = {i, j, k}; // end point
                    }
                    if (s[k] == '#') {
                        dist[i][j][k] = -1; // wall
                    }
                }
            }
        }

        // 탐색
        while (!Q.empty()) {
            tuple<int, int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 6; dir++) {
                int nz = get<0>(cur) + dz[dir];
                int nx = get<1>(cur) + dx[dir];
                int ny = get<2>(cur) + dy[dir];
                if (nz < 0 || nx < 0 || ny < 0 || nz >= h || nx >= n || ny >= m) continue;
                if (vis[nz][nx][ny] == 1 || board[nz][nx][ny] == '#') continue;
                vis[nz][nx][ny] = 1;
                Q.push({nz, nx, ny});
                dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }
        x = dist[get<0>(endPoint)][get<1>(endPoint)][get<2>(endPoint)];
        if (x == -99) {
            cout << "Trapped!" << endl;
        } else {
            cout << "Escaped in " << x <<" minute(s)." << endl;
        }
    }
}