#include <bits/stdc++.h>
using namespace std;

int ans = -1;
int vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
char board[100][100];

int dfs(int x, int y) {
    vis[x][y] = 1;
    int cnt = 1;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (vis[nx][ny] == 1 || board[nx][ny] == '.') continue;
        vis[nx][ny] = 1;
        cnt += dfs(nx, ny);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = '.';
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        board[a-1][b-1] = '#';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#' && vis[i][j] == 0) {
                ans = max(dfs(i, j), ans);
            }
        }
    }
    cout << ans;
}