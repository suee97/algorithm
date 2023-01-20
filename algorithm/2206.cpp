#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    cin >> n >> m;
    
    int board[n][m];
    int vis[n][m];
    int dist[n][m];
    int ans = -1;

    // 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = 0;
            vis[i][j] = 0;
            dist[i][j] = -99;
        }
    }
    dist[0][0] = 1;
    vis[0][0] = 1;
    
    // 입력
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
            if (board[i][j] == 1) dist[i][j] = -1;
        }
    }

    // 거리 계산
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }

    cout << endl << "= DISTANCE =" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }

    // ans 갱신
    ans = dist[n-1][m-1];

    // 부술 벽 정하기
    int destroy_x = -1;
    int destroy_y = -1;
    int destory_max = 0;
    
    // 모르겠어 ㅠ

    if (destroy_x != -1 && destroy_y != -1) {
        board[destroy_x][destroy_y] = 0;

        // 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
                dist[i][j] = -99;
            }
        }
        dist[0][0] = 1;
        vis[0][0] = 1;

        Q.push({0, 0});
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
                vis[nx][ny] = 1;
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
        ans = dist[n-1][m-1];
    }

    cout << endl << "= NEW DISTANCE =" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }

    if (ans < 0) {
        cout << "-1";
    } else {
        cout << ans;
    }
}