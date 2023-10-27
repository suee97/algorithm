#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[51][51];
vector<pair<int, int>> canInput;
vector<int> dist_v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                canInput.push_back({i, j});
            }
        }
    }

    for (int num = 0; num < pow(2, canInput.size()); num++) {
        int tmp = num;
        vector<int> binary;
        for (int i = 0; i < canInput.size(); i++) {
            int brute = tmp % 2;
            binary.push_back(brute);
            tmp /= 2;
        }
        int oneCount = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == 1) oneCount++;
        }
        if (oneCount != m) continue;

        int tmpBoard[51][51];
        int dist[51][51];
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmpBoard[i][j] = board[i][j];
                dist[i][j] = -1;
            }
        }
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == 1) {
                tmpBoard[canInput[i].first][canInput[i].second] = 3; // 실제 바이러스 위치
                dist[canInput[i].first][canInput[i].second] = 0;
                q.push({canInput[i].first, canInput[i].second});
            }
        }

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (dist[nx][ny] != -1 || tmpBoard[nx][ny] == 1) continue;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }

        int flag = 0; // -1 하나라도 있으면 1
        int maxDist = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tmpBoard[i][j] == 1) continue;
                if (dist[i][j] == -1) {
                    flag = 1;
                }
                if (dist[i][j] >= 0 && dist[i][j] > maxDist) {
                    maxDist = dist[i][j];
                }
            }
        }
        if (flag != 1) {
            dist_v.push_back(maxDist);
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < dist_v.size(); i++) {
        if (dist_v[i] < ans) ans = dist_v[i];
    }
    if (ans == INT_MAX) ans = -1;

    cout << ans;
}