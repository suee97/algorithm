#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
vector<int> ans;

int main() {    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int board[400][400] = {0};
        int vis[400][400] = {0};
        int dist[400][400] = {0};
        int n, m;
        cin >> n; m = n;
        int curX, curY;
        cin >> curX >> curY;
        board[curX][curY] = 1;
        vis[curX][curY] = 1;
        int goalX, goalY;
        cin >> goalX >> goalY;
        
        queue<pair<int, int>> Q;
        Q.push({curX, curY});
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny] == 1) continue;
                vis[nx][ny] = 1;
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
        ans.push_back(dist[goalX][goalY]);
    }

    for (int i = 0; i < T; i++) {
        cout << ans.at(i) << endl;
    }
}