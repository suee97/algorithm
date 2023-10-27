#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int board[n][m];
    int vis[n][m];
    vector<int> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = 0;
            vis[i][j] = 0;
        }
    }

    for (int tmp = 0; tmp < k; tmp++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = n-d; i < n-b; i++) {
            for (int j = a; j < c; j++) {
                board[i][j] = 1;
            }
        }
    }

    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && vis[i][j] != 1) {
                int count = 1;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
                        count++;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                v.push_back(count);
            }
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << v.size() << endl;
    while (!v.empty()) {
        cout << v.back() << ' ';
        v.pop_back();
    }
}