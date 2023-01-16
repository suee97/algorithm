#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int distanceBoard[502][502];
int dis = 1;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            int tmp = s[j] - '0';
            board[i][j] = tmp;
        }
    }

    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push({0, 0});
    distanceBoard[0][0] = 1;

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); 
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            distanceBoard[nx][ny] = distanceBoard[cur.X][cur.Y] + 1;
        }
    }
    cout << distanceBoard[n-1][m-1];
}
