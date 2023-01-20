#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[27][27];
int vis[27][27];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int count = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && vis[i][j] != 1) {
                queue<pair<int, int>> Q;
                int size = 1;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                        size++;
                    }
                }
                v.push_back(size);
                count++;
            }
        }
    }

    cout << count << endl;

    sort(v.begin(), v.end(), greater<int>());
    while (!v.empty()) {
        cout << v.back() << endl;
        v.pop_back();
    }
}