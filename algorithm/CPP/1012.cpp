#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m, K;
        cin >> m >> n >> K;
        int board[52][52] = {0};
        int vis[52][52] = {0};
        queue<pair<int, int>> Q;

        for (int kc = 0; kc < K; kc++) {
            int tmpA;
            int tmpB;
            cin >> tmpA >> tmpB;
            board[tmpB][tmpA] = 1;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && vis[i][j] == 0) {
                    Q.push({i, j});
                    vis[i][j] = 1;
                    while (!Q.empty()) {
                        pair<int, int> cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                    count++;
                }
            }
        }
        v.push_back(count);
        // vis 출력
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << vis[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }

    for (int p = 0; p < T; p++) {
        cout << v.at(p) << endl;
    }
}