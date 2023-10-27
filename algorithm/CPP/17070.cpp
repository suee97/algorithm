#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int board[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 1}});
    while (!q.empty()) {
        pair<pair<int, int>, pair<int, int>> cur = q.front();
        q.pop();

        if (cur.second.first == n-1 && cur.second.second == n-1) {
            ans++;
            continue;
        }

        // 대각
        if (cur.second.second - cur.first.second == 1 && cur.second.first - cur.first.first == 1) {
            if (cur.second.second + 1 < n && board[cur.second.first][cur.second.second + 1] != 1) {
                q.push({cur.second, {cur.second.first, cur.second.second + 1}});
            }
            if (cur.second.first + 1 < n && board[cur.second.first+1][cur.second.second] != 1) {
                q.push({cur.second, {cur.second.first+1, cur.second.second}});
            }
            if (cur.second.second + 1 < n && cur.second.first + 1 < n && 
                board[cur.second.first][cur.second.second + 1] != 1 && 
                board[cur.second.first + 1][cur.second.second] != 1 &&
                board[cur.second.first + 1][cur.second.second + 1] != 1) {
                q.push({cur.second, {cur.second.first+1, cur.second.second+1}});
            }
            continue;
        }

        // 가로
        if (cur.second.second - cur.first.second == 1) {
            if (cur.second.second + 1 < n && board[cur.second.first][cur.second.second + 1] != 1) {
                q.push({cur.second, {cur.second.first, cur.second.second + 1}});
            }
            if (cur.second.second + 1 < n && cur.second.first + 1 < n && 
                board[cur.second.first][cur.second.second + 1] != 1 && 
                board[cur.second.first + 1][cur.second.second] != 1 &&
                board[cur.second.first + 1][cur.second.second + 1] != 1) {
                q.push({cur.second, {cur.second.first+1, cur.second.second+1}});
            }
            continue;
        }

        // 세로
        if (cur.second.first - cur.first.first == 1) {
            if (cur.second.first + 1 < n && board[cur.second.first+1][cur.second.second] != 1) {
                q.push({cur.second, {cur.second.first+1, cur.second.second}});
            }
            if (cur.second.second + 1 < n && cur.second.first + 1 < n && 
                board[cur.second.first][cur.second.second + 1] != 1 && 
                board[cur.second.first + 1][cur.second.second] != 1 &&
                board[cur.second.first + 1][cur.second.second + 1] != 1) {
                q.push({cur.second, {cur.second.first+1, cur.second.second+1}});
            }
            continue;
        }

    }

    cout << ans;
}