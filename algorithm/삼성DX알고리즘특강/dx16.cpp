#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;

    string** board = new string*[n];
    for (int i = 0; i < n; i++)
        board[i] = new string[n];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            board[i][j] = s[j];
        }
    }

    cout << '\n' << "### 초기Board ###" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    int spCnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == "*") {
                spCnt++;
                continue;
            }
            int cnt = 0;
            for (int dir = 0; dir < 8; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (board[nx][ny] == "*") cnt++;
            }
            board[i][j] = to_string(cnt);
        }
    }

    cout << '\n' << "### 숫자 표시 ###" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    int zeroCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != "0") continue;

            int vis[n][n];
            memset(vis, 0, sizeof(vis));

            vis[i][j] = 1;
            board[i][j] = "#";
            spCnt++;

            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 8; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny]) continue;
                    if (board[nx][ny] == "0" && !vis[nx][ny]) {
                        q.push({nx, ny});
                    }
                    if (board[nx][ny] != "#") {
                        board[nx][ny] = "#";
                        spCnt++;
                    }
                    vis[nx][ny] = 1;
                }
            }
            zeroCnt++;
        }
    }

    cout << '\n' << "### bfs ###" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << n*n - spCnt + zeroCnt;
}