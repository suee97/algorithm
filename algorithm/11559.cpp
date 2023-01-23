#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[12][6];
int vis[12][6];
int isBomb = 0;

void initVis() {
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            vis[i][j] = 0;
}

void bfs(char c) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] == c) {
                queue<pair<int, int>> q;
                initVis();
                vis[i][j] = 1;
                q.push({i, j});
                vector<pair<int, int>> tmpChar;
                tmpChar.push_back({i, j});
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] != c) continue;
                        tmpChar.push_back({nx, ny});
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                if (tmpChar.size() >= 4) {
                    while(!tmpChar.empty()) {
                        pair<int, int> tmpCur = tmpChar.back();
                        board[tmpCur.X][tmpCur.Y] = '.';
                        tmpChar.pop_back();
                    }
                    isBomb++;
                }
            }
        }
    }
}

void moveDown() {
    for (int i = 0; i < 6; i++) {
        queue<char> tmpQ;
        for (int j = 11; j >= 0; j--) {
            if (board[j][i] != '.') tmpQ.push(board[j][i]);
            board[j][i] = '.';
        }
        for (int j = 11; j >= 0; j--) {
            if (tmpQ.empty()) continue;
            board[j][i] = tmpQ.front();
            tmpQ.pop();
        }
    }
}

int main() {
    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++) {
            board[i][j] = s[j];
        }
    }

    int ans = 0;
    while (1) {
        isBomb = 0;
        bfs('R');
        bfs('G');
        bfs('B');
        bfs('P');
        bfs('Y');
        moveDown();
        if (!isBomb) {
            break;
        } else {
            ans++;
        }
    }

    cout << ans;
}