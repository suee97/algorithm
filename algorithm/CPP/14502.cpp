#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[8][8];
int newBoard[8][8];
int maxCnt = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> zero_v;

void copyBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            newBoard[i][j] = board[i][j];
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    int vis[n][m];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
            if (board[i][j] == 2) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] == 1 || newBoard[nx][ny] != 0) continue;
            vis[nx][ny] = 1;
            newBoard[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (newBoard[i][j] == 0) cnt++;
        }
    }
    if (cnt > maxCnt) maxCnt = cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                zero_v.push_back({i, j});
            }
        }
    }

    for (int tmp = 0; tmp < pow(zero_v.size(), 3); tmp++) {
        int brute = tmp;
        copyBoard();
        set<pair<int, int>> s;
        for (int i = 0; i < 3; i++) {
            int index = brute % zero_v.size();
            brute /= zero_v.size();
            s.insert({zero_v[index].first, zero_v[index].second});
        }
        if (s.size() != 3) {
            continue;
        }
        set<pair<int, int>>::iterator iter;
        for(iter = s.begin(); iter != s.end(); iter++){
            newBoard[(*iter).first][(*iter).second] = 1;
        }
        bfs();
    }
    cout << maxCnt;
}