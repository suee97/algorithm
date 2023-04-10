#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
int board[20][20];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int isStop = 0;
    int curSize = 2;
    pair<int, int> initShark;
    queue<pair<int, int>> q;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) initShark = {i, j};
        }
    }

    q.push(initShark);
    
    while (!isStop) {
        int vis[20][20];
        fill(&vis[0][0], &vis[0][0] + 400, 0);
            
        int dis[20][20];
        fill(&dis[0][0], &dis[0][0] + 400, -1);
        
        vis[initShark.X][initShark.Y] = 1;
        dis[initShark.X][initShark.Y] = 0;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (board[nx][ny] > curSize || vis[nx][ny] == 1) continue;
                
            }
        }
    }
}