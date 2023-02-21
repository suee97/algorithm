#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, L, R;
int board[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;
int isStop = 0;

void bfs() {
    int vis[n][n];
    int localCount = 0;
    fill(&vis[0][0], &vis[0][0] + (n*n), 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 1) continue;
            vector<pair<int, int>> selected;
            int elementCount = 1;
            int elementSum = board[i][j];
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            selected.push_back({i, j});
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                    if (vis[nx][ny] == 1) continue;
                    if (abs(board[cur.X][cur.Y] - board[nx][ny]) >= L && abs(board[cur.X][cur.Y] - board[nx][ny]) <= R) {
                        selected.push_back({nx, ny});
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        elementCount++;
                        elementSum += board[nx][ny];
                    }
                }
            }
            if (elementCount < 2) continue;
            localCount++;
            int val = elementSum / elementCount;
            while (!selected.empty()) {
                board[selected.back().X][selected.back().Y] = val;
                selected.pop_back();
            }
        }
    }
    if (localCount == 0) isStop = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> L >> R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while (1) {
        bfs();
        if (isStop) {
            break;
        } else {
            cnt++;
        }
    }

    cout << cnt;
}